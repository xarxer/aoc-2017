### Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(AOCUtils SHARED
    "include/AOCUtils/global.h"
    "include/AOCUtils/io.h"
    "src/io.cpp"
)

target_include_directories(AOCUtils
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(AOCUtils
PRIVATE
    BUILD_AOCUTILS_LIB
)

