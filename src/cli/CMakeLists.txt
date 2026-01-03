find_package(CLI11 REQUIRED)

add_executable(treesize-cli main.cpp display.cpp)

target_link_libraries(treesize-cli PRIVATE core CLI11::CLI11)
