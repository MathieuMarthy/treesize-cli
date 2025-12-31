find_package(stb REQUIRED)

add_library(core STATIC
    treesize.h
    treesize.cpp
    fileModel.h
    fileModel.cpp
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(core PRIVATE stb::stb)
