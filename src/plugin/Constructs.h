#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/io/printer.h>
#include <string>
#include <sstream>
#include <vector>

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
        m_printer->Indent();
    }
    ~CSharpNamespace()
    {
        m_printer->Outdent();
        m_printer->Print("}\n");
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
        m_printer->Indent();


        m_printer->Print("readonly $name$.$name$Client _client;\n\n", "name", msg->name());

        m_printer->Print("public $name$Controller($name$.$name$Client client)\n", "name", msg->name());
        m_printer->Print("{\n");
        m_printer->Indent();
        m_printer->Print("_client = client;\n");
        m_printer->Outdent();
        m_printer->Print("}\n");
    }
    ~MvcController()
    {
        m_printer->Outdent();
        m_printer->Print("}\n");
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

        m_writeMethod = !isInputTypeStreamed && !isOutputTypeStreamed;

        //Dunno how to map streamed input/output yet
        if (m_writeMethod)
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

            m_printer->Print("public async Task<ActionResult<$output_type$>> $name$($input_type$ input)\n",
                "name", msg->name(),
                "input_type", inputTypeName,
                "output_type", outputTypeName);
            m_printer->Print("{\n");
            m_printer->Indent();

            m_printer->Print("$output_type$ result = null;\n", "output_type", outputType->name());
            m_printer->Print("try\n");
            m_printer->Print("{\n");
            m_printer->Indent();

            if (isOutputTypeStreamed)
            {
                m_printer->Print("result = await _client.$name$(input);\n", "name", msg->name());
            }
            else
            {
                m_printer->Print("result = await _client.$name$Async(input);\n", "name", msg->name());
            }

            m_printer->Outdent();
            m_printer->Print("}\n");
            m_printer->Print("catch (Exception ex)\n");
            m_printer->Print("{\n");
            m_printer->Indent();
            m_printer->Print("Response.StatusCode = 500;\n");
            m_printer->Outdent();
            m_printer->Print("}\n");
            m_printer->Print("return result;\n");
        }
    }
    ~MvcControllerActionMethod()
    {
        if (m_writeMethod)
        {
            m_printer->Outdent();
            m_printer->Print("}\n");
        }
    }

private:
    Printer* m_printer;
    bool m_writeMethod;
};

#endif