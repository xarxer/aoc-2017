#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iterator>
#include <iostream>

#include "AOCUtils/global.h"

namespace AOC {

AOCUTILS_API
std::string read_line(std::string filename, uint32_t line = 1);

AOCUTILS_API
std::vector<std::string> read_lines(std::string filename);

AOCUTILS_API
std::vector<std::string> split_string(std::string line);

AOCUTILS_API
void print_header(std::string day);

template <typename T>
std::vector<T> convert_strings(std::vector<std::string> const& strings) {
    std::vector<T> result;

    for(std::string const& str : strings) {
        std::stringstream ss(str);
        T t;
        ss >> t;
        result.push_back(t);
    }

    return result;
}

template <typename T>
void print_vector(std::vector<T> const& vec) {
    std::ostringstream ss;
    std::copy(vec.cbegin(), vec.cend() - 1, std::ostream_iterator<T>(ss, ", ")); ss << vec.back();

    std::cout << "{" << ss.str() << "}" << std::endl;
}

}

