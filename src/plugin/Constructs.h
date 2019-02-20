#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/io/printer.h>
#include "aspnetcore.pb.h"
#include <string>
#include <sstream>
#include <vector>

// Can't change indentation size. Ugh!

#define PRINTER_INDENT(p) \
    p->Indent(); p->Indent()

#define PRINTER_OUTDENT(p) \
    p->Outdent(); p->Outdent()

using namespace google::protobuf;
using namespace google::protobuf::compiler;
using namespace google::protobuf::io;

void SplitStrings(const std::string& str, const char delimiter, std::vector<std::string>& strings)
{
    std::istringstream f(str);
    std::string s;
    while (std::getline(f, s, delimiter)) 
    {
        strings.push_back(s);
    }
}

class CSharpNamespace
{
public:
    CSharpNamespace(const FileDescriptor * file, Printer* printer)
        : m_printer(printer)
    {
        m_printer->Print("using Microsoft.AspNetCore.Mvc;\n");
        m_printer->Print("using System;\n");
        m_printer->Print("using System.Collections.Generic;\n");
        m_printer->Print("using System.Threading.Tasks;\n\n");

        m_printer->Print("namespace $ns$\n", "ns", file->package());
        m_printer->Print("{\n");
        PRINTER_INDENT(m_printer); //Begin namespace
    }
    ~CSharpNamespace()
    {
        PRINTER_OUTDENT(m_printer);
        m_printer->Print("}\n"); //End namespace
    }

private:
    Printer* m_printer;
};

class MvcController
{
public:
    MvcController(const ServiceDescriptor* msg, Printer* printer)
        : m_printer(printer)
    {
        SourceLocation srcLoc;
        if (msg->GetSourceLocation(&srcLoc))
        {
            m_printer->Print("/// <summary>\n");

            std::vector<std::string> comments;
            SplitStrings(srcLoc.leading_comments, '\n', comments);
            for (auto const& cmnt : comments)
            {
                m_printer->Print("/// ");
                m_printer->Print(cmnt.c_str());
                m_printer->Print("\n");
            }

            comments.clear();
            SplitStrings(srcLoc.trailing_comments, '\n', comments);
            for (auto const& cmnt : comments)
            {
                m_printer->Print("/// ");
                m_printer->Print(cmnt.c_str());
                m_printer->Print("\n");
            }

            m_printer->Print("/// </summary>\n");
        }
        m_printer->Print("[Route(\"api/[controller]\")]\n");
        m_printer->Print("[ApiController]\n");
        m_printer->Print("public partial class $name$Controller : ControllerBase\n", "name", msg->name());
        m_printer->Print("{\n");
        PRINTER_INDENT(m_printer); //Begin Controller

        m_printer->Print("readonly $name$.$name$Client _client;\n\n", "name", msg->name());

        m_printer->Print("public $name$Controller($name$.$name$Client client)\n", "name", msg->name());
        m_printer->Print("{\n"); //Begin controller
        PRINTER_INDENT(m_printer);
        m_printer->Print("_client = client;\n");
        PRINTER_OUTDENT(m_printer);
        m_printer->Print("}\n"); //End controller
    }
    ~MvcController()
    {
        PRINTER_OUTDENT(m_printer);
        m_printer->Print("}\n"); //End Controller
    }

private:
    Printer* m_printer;
};

class MvcControllerActionMethod
{
public:
    MvcControllerActionMethod(const MethodDescriptor* msg, Printer* printer)
        : m_printer(printer), m_writeMethod(true)
    {
        auto inputType = msg->input_type();
        auto outputType = msg->output_type();

        auto isInputTypeStreamed = msg->client_streaming();
        auto isOutputTypeStreamed = msg->server_streaming();

        auto options = msg->options();
        m_writeMethod = !isInputTypeStreamed && !isOutputTypeStreamed && options.HasExtension(aspnet::core::api);

        //Dunno how to map streamed input/output yet
        if (m_writeMethod)
        {   
            //m_printer->Print("/*\n");
            //m_printer->Print(options.DebugString().c_str());
            //m_printer->Print("*/\n");
            SourceLocation srcLoc;
            if (msg->GetSourceLocation(&srcLoc))
            {
                m_printer->Print("/// <summary>\n");

                std::vector<std::string> comments;
                SplitStrings(srcLoc.leading_comments, '\n', comments);
                for (auto const& cmnt : comments)
                {
                    m_printer->Print("/// ");
                    m_printer->Print(cmnt.c_str());
                    m_printer->Print("\n");
                }

                comments.clear();
                SplitStrings(srcLoc.trailing_comments, '\n', comments);
                for (auto const& cmnt : comments)
                {
                    m_printer->Print("/// ");
                    m_printer->Print(cmnt.c_str());
                    m_printer->Print("\n");
                }

                m_printer->Print("/// </summary>\n");
            }

            std::string inputTypeName;
            std::string outputTypeName;

            if (isOutputTypeStreamed)
            {
                outputTypeName = "IEnumerable<";
                outputTypeName += outputType->name();
                outputTypeName += ">";
            }
            else
            {
                outputTypeName = outputType->name();
            }
            if (isInputTypeStreamed)
            {
                inputTypeName = "IEnumerable<";
                inputTypeName += inputType->name();
                inputTypeName += ">";
            }
            else
            {
                inputTypeName = inputType->name();
            }

            auto routeOption = options.GetExtension(aspnet::core::api);
            auto method = routeOption.method();
            switch (method)
            {
            case aspnet::core::HttpMethod::HttpMethod_Get:
                {
                    if (routeOption.has_route_pattern())
                        m_printer->Print("[HttpGet(\"$route_pattern$\")]\n", "route_pattern", routeOption.route_pattern().value());
                    else
                        m_printer->Print("[HttpGet(nameof($route_pattern$))]\n", "route_pattern", msg->name());
                }
                break;
            case aspnet::core::HttpMethod::HttpMethod_Post:
                {
                    if (routeOption.has_route_pattern())
                        m_printer->Print("[HttpPost(\"$route_pattern$\")]\n", "route_pattern", routeOption.route_pattern().value());
                    else
                        m_printer->Print("[HttpPost(nameof($route_pattern$))]\n", "route_pattern", msg->name());
                }
                break;
            case aspnet::core::HttpMethod::HttpMethod_Put:
                {
                    if (routeOption.has_route_pattern())
                        m_printer->Print("[HttpPut(\"$route_pattern$\")]\n", "route_pattern", routeOption.route_pattern().value());
                    else
                        m_printer->Print("[HttpPut(nameof($route_pattern$))]\n", "route_pattern", msg->name());
                }
                break;
            case aspnet::core::HttpMethod::HttpMethod_Delete:
                {
                    if (routeOption.has_route_pattern())
                        m_printer->Print("[HttpDelete(\"$route_pattern$\")]\n", "route_pattern", routeOption.route_pattern().value());
                    else
                        m_printer->Print("[HttpDelete(nameof($route_pattern$))]\n", "route_pattern", msg->name());
                }
                break;
            default:
                {
                    m_printer->Print("#warning Encountered unsupprted method option annotation: $method$\n", "method", aspnet::core::HttpMethod_Name(method));
                }
                break;
            }

            std::string inputAttr;
            switch (routeOption.source())
            {
            case aspnet::core::HttpInputSource::HttpInputSource_Body:
                inputAttr = "[FromBody]";
                break;
            case aspnet::core::HttpInputSource::HttpInputSource_Form:
                inputAttr = "[FromForm]";
                break;
            case aspnet::core::HttpInputSource::HttpInputSource_Header:
                inputAttr = "[FromHeader]";
                break;
            case aspnet::core::HttpInputSource::HttpInputSource_Query:
                inputAttr = "[FromQuery]";
                break;
            }

            m_printer->Print("public async Task<ActionResult<$output_type$>> $name$($input_attr$$input_type$ input)\n",
                "name", msg->name(),
                "input_attr", inputAttr,
                "input_type", inputTypeName,
                "output_type", outputTypeName);
            m_printer->Print("{\n");
            PRINTER_INDENT(m_printer); //Begin method

            m_printer->Print("$output_type$ result = null;\n", "output_type", outputType->name());
            m_printer->Print("try\n");
            m_printer->Print("{\n");
            PRINTER_INDENT(m_printer); //Begin try

            if (isOutputTypeStreamed)
            {
                m_printer->Print("result = await _client.$name$(input);\n", "name", msg->name());
            }
            else
            {
                m_printer->Print("result = await _client.$name$Async(input);\n", "name", msg->name());
            }

            PRINTER_OUTDENT(m_printer);
            m_printer->Print("}\n"); //End try
            m_printer->Print("catch (Exception ex)\n");
            m_printer->Print("{\n"); //Begin catch
            PRINTER_INDENT(m_printer);
            m_printer->Print("Response.StatusCode = 500;\n");
            PRINTER_OUTDENT(m_printer);
            m_printer->Print("}\n"); //End catch
            m_printer->Print("return result;\n");
        }
    }
    ~MvcControllerActionMethod()
    {
        if (m_writeMethod)
        {
            PRINTER_OUTDENT(m_printer); //End method
            m_printer->Print("}\n");
        }
    }

private:
    Printer* m_printer;
    bool m_writeMethod;
};

#endif