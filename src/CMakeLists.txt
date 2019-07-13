add_executable(main main.cpp)
add_library(dll dll.cpp)
add_library(stack stack.cpp)

target_link_libraries(main dll stack)
