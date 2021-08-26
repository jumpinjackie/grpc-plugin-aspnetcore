#include "AspNetCoreGenerator.h"
#include "Constructs.h"

bool AspNetCoreGenerator::Generate(const FileDescriptor * file,
                                   const string & parameter,
                                   GeneratorContext * generator_context,
                                   string * error) const
{
    std::vector<std::pair<string, string>> params;
    ParseGeneratorParameter(parameter, &params);
    bool generateProject = false;
    std::string name = "My GRPC Gateway";
    std::string defaultHost = "localhost";
    std::string defaultPort = "7000";
    std::vector<std::string> projectRefs;

    for (auto const& p : params)
    {
        if (p.first == "generate_project" && (p.second == "true" || p.second == "1"))
        {
            generateProject = true;
        }
        else if (p.first == "port")
        {
            defaultPort = p.second;
        }
        else if (p.first == "name")
        {
            name = p.second;
        }
        else if (p.first == "host")
        {
            defaultHost = p.second;
        }
        else if (p.first == "project_ref")
        {
            projectRefs.push_back(p.second);
        }
    }

    if (generateProject)
    {
        std::string projectName = file->package() + ".GrpcGateway.csproj";

        // Generate Project
        auto *projOutStream = generator_context->Open(projectName);
        Printer projPrinter(projOutStream, '$');
        projPrinter.Print("<Project Sdk=\"Microsoft.NET.Sdk.Web\">\n");
        {
            Indent i1(&projPrinter);
            projPrinter.Print("<PropertyGroup>\n");
            {
                Indent i2(&projPrinter);
                projPrinter.Print("<TargetFramework>net5.0</TargetFramework>\n");
                projPrinter.Print("<AspNetCoreHostingModel>InProcess</AspNetCoreHostingModel>\n");
                projPrinter.Print("<LangVersion>latest</LangVersion>\n");
            }
            projPrinter.Print("</PropertyGroup>\n");
            projPrinter.Print("<ItemGroup>\n");
            {
                Indent i2(&projPrinter);
                projPrinter.Print("<PackageReference Include=\"Google.Protobuf\" Version=\"3.17.3\" />\n");
                projPrinter.Print("<PackageReference Include=\"Grpc.Core\" Version=\"2.38.1\" />\n");
                projPrinter.Print("<PackageReference Include=\"Microsoft.AspNetCore.Mvc.NewtonsoftJson\" Version=\"5.0.9\" />\n");
                projPrinter.Print("<PackageReference Include=\"NSwag.AspNetCore\" Version=\"13.13.2\" />\n");
            }
            projPrinter.Print("</ItemGroup>\n");

            if (projectRefs.size() > 0)
            {
                projPrinter.Print("<ItemGroup>\n");
                {
                    Indent iRefs(&projPrinter);
                    for (auto const& ref : projectRefs)
                    {
                        std::string refEl = "<ProjectReference Include=\"";
                        refEl += ref;
                        refEl += "\" />\n";
                        projPrinter.Print(refEl.c_str());
                    }
                }
                projPrinter.Print("</ItemGroup>\n");
            }
        }
        projPrinter.Print("</Project>");
        

        std::cerr << "Wrote: " << projectName << std::endl;

        // Write Program.cs
        auto *progCsOutput = generator_context->Open("Program.cs");
        Printer progCsPrinter(progCsOutput, '$');

        progCsPrinter.Print("using Microsoft.AspNetCore;\n");
        progCsPrinter.Print("using Microsoft.AspNetCore.Hosting;\n\n");
        progCsPrinter.Print("#pragma warning disable 1591\n\n");
        progCsPrinter.Print("namespace $ns$\n", "ns", file->package());
        {
            CodeBlock nsStart(&progCsPrinter);
            progCsPrinter.Print("public class Program\n");
            {
                CodeBlock classStart(&progCsPrinter);
                progCsPrinter.Print("public static void Main(string[] args)\n");
                {
                    CodeBlock mainStart(&progCsPrinter, "\n");
                    progCsPrinter.Print("var host = CreateWebHostBuilder(args).Build();\n");
                    progCsPrinter.Print("host.Run();\n");
                }
                progCsPrinter.Print("public static IWebHostBuilder CreateWebHostBuilder(string[] args)\n");
                {
                    CodeBlock createHbStart(&progCsPrinter);
                    progCsPrinter.Print("return WebHost.CreateDefaultBuilder(args).UseStartup<Startup>();\n");
                }
            }
        }

        std::cerr << "Wrote: Program.cs" << std::endl;

        // Write Startup.cs
        auto *startupCsOutput = generator_context->Open("Startup.cs");
        Printer startupCsPrinter(startupCsOutput, '$');

        startupCsPrinter.Print("using Grpc.Core;\n");
        startupCsPrinter.Print("using Microsoft.AspNetCore.Builder;\n");
        startupCsPrinter.Print("using Microsoft.AspNetCore.Hosting;\n");
        startupCsPrinter.Print("using Microsoft.Extensions.Configuration;\n");
        startupCsPrinter.Print("using Microsoft.Extensions.DependencyInjection;\n");
        startupCsPrinter.Print("using Microsoft.Extensions.Hosting;\n");
        startupCsPrinter.Print("using Newtonsoft.Json.Converters;\n");
        startupCsPrinter.Print("#pragma warning disable 1591\n\n");
        startupCsPrinter.Print("namespace $ns$\n", "ns", file->package());
        {
            CodeBlock nsStart(&startupCsPrinter);
            startupCsPrinter.Print("public class Startup\n");
            {
                CodeBlock startupStart(&startupCsPrinter);
                startupCsPrinter.Print("public Startup(IConfiguration configuration)\n");
                {
                    CodeBlock ctorStart(&startupCsPrinter);
                    startupCsPrinter.Print("Configuration = configuration;\n");
                }
                startupCsPrinter.Print("\npublic IConfiguration Configuration { get; }\n\n");
                startupCsPrinter.Print("// This method gets called by the runtime. Use this method to add services to the container.\n");
                startupCsPrinter.Print("public void ConfigureServices(IServiceCollection services)\n");
                {
                    CodeBlock configureSvcStart(&startupCsPrinter);

                    startupCsPrinter.Print("var grpcConf = Configuration.GetSection(\"grpc\");\n");
                    startupCsPrinter.Print("var host = grpcConf[\"host\"] ?? \"$host$\";\n", "host", defaultHost);
                    startupCsPrinter.Print("var port = $port$;\n", "port", defaultPort);
                    startupCsPrinter.Print("if (int.TryParse(grpcConf[\"port\"], out var p))\n");
                    {
                        CodeBlock ifBlock(&startupCsPrinter);
                        startupCsPrinter.Print("port = p;\n");
                    }

                    startupCsPrinter.Print("var ch = new Channel(host, port, ChannelCredentials.Insecure);\n");
                    startupCsPrinter.Print("services.AddSingleton(ch);\n");

                    for (int i = 0; i < file->service_count(); i++)
                    {
                        auto svc = file->service(i);
                        startupCsPrinter.Print("services.AddTransient(sp => new $service$.$service$Client(sp.GetRequiredService<Channel>()));\n",
                            "service",
                            svc->name());
                    }
                    
                    startupCsPrinter.Print("services.AddMvc()\n");
                    startupCsPrinter.Print("    .AddNewtonsoftJson(options =>\n");
                    startupCsPrinter.Print("        options.SerializerSettings.Converters.Add(new StringEnumConverter()));\n");
                    startupCsPrinter.Print("services.AddSwaggerDocument(c =>\n");
                    {
                        CodeBlock swaggerGenStart(&startupCsPrinter, ");");
                        startupCsPrinter.Print("c.Title = \"$name$\";\n", "name", name);
                        startupCsPrinter.Print("c.Version = \"v1\";\n");
                    }
                }
                startupCsPrinter.Print("// This method gets called by the runtime. Use this method to configure the HTTP request pipeline.\n");
                startupCsPrinter.Print("public void Configure(IApplicationBuilder app, IWebHostEnvironment env)\n");
                {
                    CodeBlock configureStart(&startupCsPrinter);
                    startupCsPrinter.Print("if (env.IsDevelopment())\n");
                    {
                        CodeBlock ifBlock(&startupCsPrinter);
                        startupCsPrinter.Print("app.UseDeveloperExceptionPage();\n");
                    }
                    startupCsPrinter.Print("else\n");
                    {
                        CodeBlock elseBlock(&startupCsPrinter);
                        startupCsPrinter.Print("// The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.\n");
                        startupCsPrinter.Print("app.UseHsts();\n");
                    }

                    startupCsPrinter.Print("app.UseHttpsRedirection();\n");
                    startupCsPrinter.Print("app.UseRouting();\n");
                    startupCsPrinter.Print("app.UseEndpoints(endpoints =>\n");
                    startupCsPrinter.Print("{\n");
                    startupCsPrinter.Print("    endpoints.MapDefaultControllerRoute();\n");
                    startupCsPrinter.Print("});\n");
                    startupCsPrinter.Print("app.UseOpenApi();\n");
                    startupCsPrinter.Print("app.UseSwaggerUi3();\n");
                }
            }
        }

        std::cerr << "Wrote: Startup.cs" << std::endl;
    }
    // Generate Controllers
    for (int i = 0; i < file->service_count(); ++i)
    {
        auto svc = file->service(i);
        std::string ctrlFileName = svc->name() + "Controller.g.cs";
        auto *ctrlOutStream = generator_context->Open(ctrlFileName);
        Printer svcPrinter(ctrlOutStream, '$');
        CSharpNamespace ns(file, &svcPrinter);
        MvcController ctrl(svc, &svcPrinter);
        for (int j = 0; j < svc->method_count(); ++j)
        {
            auto m = svc->method(j);
            MvcControllerActionMethod method(m, &svcPrinter);
        }

        std::cerr << "Wrote: " << ctrlFileName << std::endl;
    }
    return true;
}
