#include <vector>
#include <iostream>
#include <algorithm>

#include <AOCUtils/io.h>

uint32_t part_one(std::vector<std::vector<uint32_t>> const& numbers)
{
    uint32_t sum = 0;

    for(auto const& sub_vector : numbers) {
        auto minmax = std::minmax_element(sub_vector.cbegin(), sub_vector.cend());
        sum += *minmax.second - *minmax.first;
    }

    return sum;
}

uint32_t part_two(std::vector<std::vector<uint32_t>> const& numbers)
{
    uint32_t sum = 0;

    // TODO: Maybe use std::find_first_of
    for(auto const& sub_vector : numbers) {
        for(auto it = sub_vector.cbegin(); it != sub_vector.cend(); it++) {
            for(auto comp = std::next(it); comp != sub_vector.cend(); comp++) {
                if(*it % *comp == 0) {
                    sum += (*it / *comp);
                }
                else if(*comp % *it == 0) {
                    sum += (*comp / *it);
                }
            }
        }
    }

    return sum;
}

int main()
{
    AOC::print_header("02");

    auto lines = AOC::read_lines("input.txt");

    std::vector<std::vector<uint32_t>> numbers;
    for(std::string const& str : lines) {
        numbers.push_back(AOC::convert_strings<uint32_t>(AOC::split_string(str)));
    }

    std::cout << "Solution for part one: " << part_one(numbers) << std::endl;
    std::cout << "Solution for part two: " << part_two(numbers) << std::endl;

}
