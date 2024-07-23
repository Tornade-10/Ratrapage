file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(api ${SRC_FILES} ${HEADER_FILES})
target_include_directories(api PUBLIC include/)

if(ENABLE_PROFILING)
    target_link_libraries(api PRIVATE Tracy::TracyClient)
    target_compile_definitions(api PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

#add_executable(api_test test/test_vec2i.cc)
target_link_libraries(api PRIVATE sfml-system sfml-graphics sfml-window sfml-audio)

#add_test(Api api_test)