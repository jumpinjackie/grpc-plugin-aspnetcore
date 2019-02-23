# grpc-plugin-aspnetcore

ASP.net reverse proxy generator for GRPC services

## Overview

This plugin will help generate a series of ASP.net core Web API controllers for each gRPC service defined.

This is intended to be the asp.net core analogue of [grpc-gateway](https://github.com/grpc-ecosystem/grpc-gateway)

## Requirements

* Protocol buffers 3.6.1 (built as dynamic)

This repo assumes protobuf was acquired with [vcpkg](https://github.com/Microsoft/vcpkg) and was built with dynamic linkage. It assumes you exported protobuf from vcpkg into `thirdparty/vcpkg-export`

## Usage

Add the `protoc-plugin-aspnetcore` binary to your GRPC tools path

Then run `protoc` as follows:

```
protoc -I<path to aspnetcore.proto> --plugin=protoc-gen-aspnetcore=<path to protoc_plugin_aspnetcore> <path to your grpc .proto file(s)> --aspnetcore_out=<output path for your generated sources>
```

## Generator options

You may prefix the `--aspnetcore_out` option with extra options like so:

```
--aspnetcore_out:<comma-delimited list of options>:<output path>
```

The following options are supported:

 * `generate_project`: Set to `1` or `true` to tell the generator to also generate a skeleton aspnetcore project. Otherwise, only the webapi controllers are generated.
    * Invocation: `--aspnetcore_out:generate_project=1:<output path>`
 * `port`: Only has effect if `generate_project` is set to `1` or `true`. The default port to use when writing GRPC channel setup code in `Startup.cs`.
    * Invocation: `--aspnetcore_out:generate_project=1,port=1234:<output path>`
 * `host`: Only has effect if `generate_project` is set to `1` or `true`. The default host to use when writing GRPC channel setup code in `Startup.cs`.
    * Invocation: `--aspnetcore_out:generate_project=1,host=127.0.0.1:<output path>`
 * `name`: Only has effect if `generate_project` is set to `1` or `true`. The default service display name to use for Swagger metadata generation.
    * Invocation: `--aspnetcore_out:generate_project=1,name="My GRPC Gateway":<output path>`
 * `project_ref`: Only has effect if `generate_project` is set to `1` or `true`. Add additional project references to the generated project. Paths specified must be relative to the output path specified.
    * Invocation: `--aspnetcore_out:generate_project=1,project_ref=..\MyProject.csproj:<output path>`

## Known Issues

If you include `aspnetcore.proto` to annotate your service methods, you will have to include `aspnetcore.proto` when 
generating gRPC clients for languages other than .net

As protobuf does not support pre-processing (eg. `#ifdef` certain sections of the file based on language target), a workaround you can use is to put your
gRPC service definitions behind text templates where `aspnetcore.proto` and your service method annotations can be selectively applied and run your template
with the desired switches to generate the required `.proto` file with or without the aspnetcore annotations.