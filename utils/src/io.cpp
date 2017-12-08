#include "AOCUtils/io.h"

#include <fstream>
#include <iostream>

namespace aoc {

std::string read_line(std::string filename, uint32_t line)
{
    std::ifstream stream(filename);
    std::string current;

    for(uint32_t i = 0; i < line; i++) {
        std::getline(stream, current);
        if(stream.good() == false) {
            return { };
        }
    }

    return current;
}

std::vector<std::string> read_lines(std::string filename)
{
    std::ifstream stream(filename);
    std::string current;

    std::vector<std::string> lines;

    while(std::getline(stream, current)) {
        lines.push_back(current);
    }

    return lines;
}

std::vector<std::string> split_string(std::string line)
{
    std::istringstream iss(line);
    return { std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>() };
}

void print_header(std::string day)
{
    std::cout << "===================================\n";
    std::cout << "======== AOC 2017 - Day " << day << " ========\n";
    std::cout << "===================================\n";
    std::cout << std::flush;
}

}
