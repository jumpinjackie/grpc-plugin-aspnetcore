#include "AspNetCoreGenerator.h"


bool AspNetCoreGenerator::Generate(const FileDescriptor * file,
                                   const string & parameter,
                                   GeneratorContext * generator_context,
                                   string * error) const
{
    auto *outstream = generator_context->Open(file->name() + ".txt");
    Printer printer(outstream, '$');
    printer.Print("Namespace: $ns$\n", "ns", file->package());
    /*
    for (int i = 0; i < file->message_type_count(); ++i) {
        PrintMessage(printer, file->message_type(i));
    }
    */
    for (int i = 0; i < file->service_count(); ++i) {
        PrintService(printer, file->service(i));
    }
    return true;
}

void AspNetCoreGenerator::PrintService(Printer& printer, const ServiceDescriptor* msg) const
{
    printer.Print("Service: $name$\n", "name", msg->name());
    printer.Indent();
    for (int i = 0; i < msg->method_count(); ++i) {
        PrintServiceMethod(printer, msg->method(i));
    }
    printer.Outdent();
}

void AspNetCoreGenerator::PrintServiceMethod(Printer& printer, const MethodDescriptor* msg) const
{
    printer.Print("Method: $name$\n", "name", msg->name());
    printer.Indent();

    auto input = msg->input_type();
    auto output = msg->output_type();

    printer.Print("Input: $name$\n", "name", input->name());
    printer.Indent();
    printer.Print("Streamed: $client_streaming$\n", "client_streaming", msg->client_streaming() ? "true" : "false");
    printer.Outdent();
    printer.Print("Output: $name$\n", "name", output->name());
    printer.Indent();
    printer.Print("Streamed: $server_streaming$\n", "server_streaming", msg->server_streaming() ? "true" : "false");
    printer.Outdent();
    printer.Outdent();
}

void AspNetCoreGenerator::PrintMessage(Printer& printer, const Descriptor* msg) const
{
    printer.Print("- $name$\n", "name", msg->name());
    printer.Indent();
    for (int i = 0; i < msg->nested_type_count(); ++i) {
        PrintMessage(printer, msg->nested_type(i));
    }
    printer.Outdent();
}