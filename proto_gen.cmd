@echo off
set TRIPLET=%1
if %TRIPLET% == "" then set TRIPLET=x64-windows
set PROTOBUF_INCLUDE=%CD%\thirdparty\vcpkg-export\installed\%TRIPLET%\include
set PROTOBUF_TOOLS=%CD%\thirdparty\vcpkg-export\installed\%TRIPLET%\tools\protobuf
set GRPC_TOOLS=%CD%\thirdparty\vcpkg-export\installed\%TRIPLET%\tools\grpc
echo [grpc]: Protoc annotations
%PROTOBUF_TOOLS%\protoc.exe -Iproto -I%PROTOBUF_INCLUDE% --cpp_out=src/plugin --plugin=protoc-gen-grpc=%GRPC_TOOLS%\grpc_cpp_plugin.exe proto/aspnetcore.proto