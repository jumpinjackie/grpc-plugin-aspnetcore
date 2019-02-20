@echo off
set PROTOBUF_INCLUDE=%CD%\thirdparty\vcpkg-export\installed\x64-windows\include
set PROTOBUF_TOOLS=%CD%\thirdparty\vcpkg-export\installed\x64-windows\tools\protobuf
set GRPC_TOOLS=%CD%\thirdparty\vcpkg-export\installed\x64-windows\tools\grpc
echo [grpc]: Protoc annotations
%PROTOBUF_TOOLS%\protoc.exe -Iproto -I%PROTOBUF_INCLUDE% --cpp_out=src/plugin --plugin=protoc-gen-grpc=%GRPC_TOOLS%\grpc_cpp_plugin.exe proto/aspnetcore.proto