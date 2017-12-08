### Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(day-04
    "main.cpp"
)

configure_file("input.txt" "input.txt" COPYONLY)

target_link_libraries(day-04 PUBLIC AOCUtils)
