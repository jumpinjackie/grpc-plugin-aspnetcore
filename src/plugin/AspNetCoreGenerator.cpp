#include "AspNetCoreGenerator.h"
#include "Constructs.h"

bool AspNetCoreGenerator::Generate(const FileDescriptor * file,
                                   const string & parameter,
                                   GeneratorContext * generator_context,
                                   string * error) const
{
    auto *outstream = generator_context->Open(file->name() + ".g.cs");
    Printer printer(outstream, '$');
    CSharpNamespace ns(file, &printer);
    {
        for (int i = 0; i < file->service_count(); ++i) 
        {
            auto svc = file->service(i);
            MvcController ctrl(svc, &printer);
            for (int j = 0; j < svc->method_count(); ++j)
            {
                auto m = svc->method(j);
                MvcControllerActionMethod method(m, &printer);
            }
        }
    }
    return true;
}