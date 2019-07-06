add_executable(main main.cpp)
add_library(liber dll.cpp)

target_link_libraries(main liber)
