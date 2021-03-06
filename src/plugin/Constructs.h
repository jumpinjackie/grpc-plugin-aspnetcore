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
#include <fstream>
#include <vector>

// Can't change indentation size. Ugh!

#define PRINTER_INDENT(p) \
    p.Indent(); p.Indent()

#define PRINTER_OUTDENT(p) \
    p.Outdent(); p.Outdent()

#define PRINTER_PTR_INDENT(p) \
    p->Indent(); p->Indent()

#define PRINTER_PTR_OUTDENT(p) \
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

class Indent
{
public:
    Indent(Printer* printer)
        : m_printer(printer)
    {
        PRINTER_PTR_INDENT(m_printer);
    }
    ~Indent()
    {
        PRINTER_PTR_OUTDENT(m_printer);
    }
private:
    Printer* m_printer;
};

class CodeBlock
{
public:
    CodeBlock(Printer* printer, char* insertAfterEndingBrace = nullptr) 
        : m_printer(printer), m_indent(nullptr), m_insertAfterEndingBrace(insertAfterEndingBrace)
    {
        m_printer->Print("{\n");
        m_indent = new Indent(printer);
    }
    ~CodeBlock()
    {
        delete m_indent;
        if (m_insertAfterEndingBrace != nullptr)
        {
            m_printer->Print("}");
            m_printer->Print(m_insertAfterEndingBrace);
            m_printer->Print("\n");
        }
        else
        {
            m_printer->Print("}\n");
        }
    }
private:
    Printer* m_printer;
    Indent* m_indent;
    char* m_insertAfterEndingBrace;
};

class CSharpNamespace
{
public:
    CSharpNamespace(const FileDescriptor * file, Printer* printer)
        : m_printer(printer), m_namespace(nullptr)
    {
        m_printer->Print("using Microsoft.AspNetCore.Mvc;\n");
        m_printer->Print("using System;\n");
        m_printer->Print("using System.Collections.Generic;\n");
        m_printer->Print("using System.Threading.Tasks;\n\n");
        m_printer->Print("#pragma warning disable 1591\n\n");
        m_printer->Print("namespace $ns$\n", "ns", file->package());
        m_namespace = new CodeBlock(m_printer);
    }
    ~CSharpNamespace()
    {
        delete m_namespace;
    }

private:
    Printer* m_printer;
    CodeBlock* m_namespace;
};

class DocCommentBlock
{
public:
    DocCommentBlock(const SourceLocation& srcLoc, Printer* printer)
        : m_printer(printer)
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
    ~DocCommentBlock()
    {

    }
private:
    Printer* m_printer;
};

class MvcController
{
public:
    MvcController(const ServiceDescriptor* msg, Printer* printer)
        : m_printer(printer), m_controller(nullptr)
    {
        SourceLocation srcLoc;
        if (msg->GetSourceLocation(&srcLoc))
        {
            DocCommentBlock comment(srcLoc, m_printer);
        }
        m_printer->Print("[Route(\"api/[controller]\")]\n");
        m_printer->Print("[ApiController]\n");
        m_printer->Print("public partial class $name$Controller : ControllerBase\n", "name", msg->name());

        m_controller = new CodeBlock(m_printer);

        m_printer->Print("// The GRPC service client\n");
        m_printer->Print("readonly $name$.$name$Client _client;\n\n", "name", msg->name());
        m_printer->Print("public $name$Controller($name$.$name$Client client)\n", "name", msg->name());
        {
            CodeBlock ctor(m_printer);
            m_printer->Print("_client = client;\n");
        }
    }
    ~MvcController()
    {
        delete m_controller;
    }

private:
    Printer* m_printer;
    CodeBlock* m_controller;
};

class MvcControllerActionMethod
{
public:
    MvcControllerActionMethod(const MethodDescriptor* msg, Printer* printer)
        : m_printer(printer), m_methodBlock(nullptr)
    {
        auto inputType = msg->input_type();
        auto outputType = msg->output_type();

        auto isInputTypeStreamed = msg->client_streaming();
        auto isOutputTypeStreamed = msg->server_streaming();

        auto options = msg->options();
        auto writeMethod = !isInputTypeStreamed && !isOutputTypeStreamed && options.HasExtension(aspnet::core::api);

        //Dunno how to map streamed input/output yet
        if (writeMethod)
        {   
            //m_printer->Print("/*\n");
            //m_printer->Print(options.DebugString().c_str());
            //m_printer->Print("*/\n");
            SourceLocation srcLoc;
            if (msg->GetSourceLocation(&srcLoc))
            {
                DocCommentBlock comment(srcLoc, m_printer);
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

            if (routeOption.custom_method_attributes_size() > 0)
            {
                for (auto const& line : routeOption.custom_method_attributes())
                {
                    m_printer->Print(line.c_str());
                }
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

            if (routeOption.is_empty_request())
            {
                if (routeOption.has_custom_return_type())
                {
                    m_printer->Print("public async Task<$output_type$> $name$()\n",
                        "name", msg->name(),
                        "output_type", routeOption.custom_return_type().value());
                }
                else
                {
                    m_printer->Print("public async Task<ActionResult<$output_type$>> $name$()\n",
                        "name", msg->name(),
                        "output_type", outputTypeName);
                }
            }
            else 
            {
                if (routeOption.has_custom_return_type())
                {
                    m_printer->Print("public async Task<$output_type$> $name$($input_attr$$input_type$ input)\n",
                        "name", msg->name(),
                        "input_attr", inputAttr,
                        "input_type", inputTypeName,
                        "output_type", routeOption.custom_return_type().value());
                }
                else
                {
                    m_printer->Print("public async Task<ActionResult<$output_type$>> $name$($input_attr$$input_type$ input)\n",
                        "name", msg->name(),
                        "input_attr", inputAttr,
                        "input_type", inputTypeName,
                        "output_type", outputTypeName);
                }
            }
            m_methodBlock = new CodeBlock(m_printer); //Begin method
            if (!routeOption.custom_method_body_template().empty())
            {
                std::ifstream fin(routeOption.custom_method_body_template());
                if (!fin.is_open())
                {
                    std::cerr << "Could not read template file: "
                        << routeOption.custom_method_body_template()
                        << std::endl;
                }
                else
                {
                    std::string line;
                    while (std::getline(fin, line))
                    {
                        PrintCustomMethodLine(line, msg, isOutputTypeStreamed, outputType, true);
                    }
                }
            }
            else if (routeOption.custom_method_body_inline_size() > 0)
            {
                for (auto const& line : routeOption.custom_method_body_inline())
                {
                    PrintCustomMethodLine(line, msg, isOutputTypeStreamed, outputType);
                }
            }
            else
            {
                m_printer->Print("var result = default($output_type$);\n", "output_type", outputType->name());
                {
                    std::unique_ptr<CodeBlock> tryStart;
                    if (routeOption.custom_exception_handling_size() > 0)
                    {
                        m_printer->Print("try\n");
                        tryStart.reset(new CodeBlock(m_printer));
                    }
                    if (routeOption.is_empty_request())
                    {
                        m_printer->Print("var input = new $input_type$();\n", "input_type", inputTypeName);
                    }
                    if (isOutputTypeStreamed)
                    {
                        m_printer->Print("result = await _client.$name$(input);\n", "name", msg->name());
                    }
                    else
                    {
                        m_printer->Print("result = await _client.$name$Async(input);\n", "name", msg->name());
                    }
                }
                if (routeOption.custom_exception_handling_size() > 0)
                {
                    m_printer->Print("catch (Exception ex)\n");
                    {
                        CodeBlock catchStart(m_printer);
                        for (auto const& line : routeOption.custom_exception_handling())
                        {
                            m_printer->Print("$line$\n", "line", line);
                        }
                    }
                }
                m_printer->Print("return result;\n");
            }
        }
    }
    ~MvcControllerActionMethod()
    {
        if (m_methodBlock)
        {
            delete m_methodBlock; //End method
        }
    }

private:
    void PrintCustomMethodLine(const std::string& line,
                               const MethodDescriptor* msg,
                               const bool isOutputTypeStreamed,
                               const Descriptor* outputType,
                               const bool newLine = false)
    {
        std::map<std::string, std::string> vars;
        if (line.find("$method_call$") != std::string::npos)
        {
            std::string methodCall = "await _client.";
            methodCall += msg->name();
            if (!isOutputTypeStreamed)
            {
                methodCall += "Async";
            }
            methodCall += "(input)";
            vars["method_call"] = methodCall;
        }
        if (line.find("$output_var$") != std::string::npos)
        {
            vars["output_var"] = "result";
        }
        if (line.find("$output_type$") != std::string::npos)
        {
            vars["output_type"] = outputType->name();
        }
        m_printer->Print(vars, line.c_str());
        if (newLine)
        {
            m_printer->Print("\n");
        }
    }

    Printer* m_printer;
    CodeBlock* m_methodBlock;
};

#endif