add_executable(main main.cpp)
add_library(dll dll.cpp)
add_library(stk stk.cpp)
add_library(que que.cpp)

target_link_libraries(stk dll)
target_link_libraries(que dll)
target_link_libraries(main dll stk que)
