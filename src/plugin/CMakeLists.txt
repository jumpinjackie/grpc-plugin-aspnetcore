project(protoc_plugin_aspnetcore CXX)

set(protoc_plugin_aspnetcore_SOURCES 
    main.cpp
    aspnetcore.pb.cc
    AspNetCoreGenerator.cpp
)

add_executable("${PROJECT_NAME}" "${protoc_plugin_aspnetcore_SOURCES}")
target_link_libraries(${PROJECT_NAME} protobuf::libprotobuf)
target_link_libraries(${PROJECT_NAME} protobuf::libprotoc)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin"
)