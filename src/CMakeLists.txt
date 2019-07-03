add_executable(main main.cpp)
add_library(hello hello.cpp)

target_link_libraries(main
    hello)
