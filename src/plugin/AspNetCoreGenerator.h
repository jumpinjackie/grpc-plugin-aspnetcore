#ifndef ASPNETCORE_GENERATOR_H
#define ASPNETCORE_GENERATOR_H

#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/io/printer.h>
#include <string>

using namespace google::protobuf;
using namespace google::protobuf::compiler;
using namespace google::protobuf::io;

class AspNetCoreGenerator : public google::protobuf::compiler::CodeGenerator {
public:
    virtual bool Generate(const FileDescriptor * file,
                          const string & parameter,
                          GeneratorContext * generator_context,
                          string * error) const;
};

#endif