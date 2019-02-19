#include "AspNetCoreGenerator.h"

int main(int argc, char** argv) {
    AspNetCoreGenerator generator;
    return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}