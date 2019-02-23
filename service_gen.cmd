@echo off
set PROTOBUF_INCLUDE=%CD%\thirdparty\vcpkg-export\installed\x64-windows\include
set PROTOBUF_TOOLS=%CD%\thirdparty\vcpkg-export\installed\x64-windows\tools\protobuf
set GRPC_TOOLS=%CD%\thirdparty\vcpkg-export\installed\x64-windows\tools\grpc
echo [grpc]: .net Client
%PROTOBUF_TOOLS%\protoc.exe -Iproto -I%PROTOBUF_INCLUDE% --csharp_opt=file_extension=.g.cs --csharp_out src/gateway --grpc_out src/gateway --plugin=protoc-gen-grpc=%GRPC_TOOLS%\grpc_csharp_plugin.exe proto/Services.proto proto/aspnetcore.proto
echo [grpc]: asp.net core gateway
%PROTOBUF_TOOLS%\protoc.exe -Iproto -I%PROTOBUF_INCLUDE% --plugin=protoc-gen-example=%CD%\build\x64-Debug\out\bin\protoc_plugin_aspnetcore.exe proto/Services.proto --example_out=generate_project=0,port=9000,host=127.0.0.1,name="GRPC Gateway":src/gateway