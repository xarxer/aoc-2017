#include <vector>
#include <iostream>
#include <algorithm>

#include <AOCUtils/io.h>

uint32_t part_one(std::vector<int32_t> numbers)
{
    uint32_t steps = 0;

    auto it = numbers.begin();
    int32_t value = 0;

    while(std::distance(it, numbers.end()) > value) {
        std::advance(it, value);

        value = *it;
        (*it) = value + 1;

        steps++;
    }

    return steps;
}

uint32_t part_two(std::vector<int32_t> numbers)
{
    uint32_t steps = 0;

    auto it = numbers.begin();
    int32_t value = 0;

    while(std::distance(it, numbers.end()) > value) {
        std::advance(it, value);

        value = *it;

        if(value >= 3) {
            (*it) = value - 1;
        }
        else {
            (*it) = value + 1;
        }

        steps++;
    }

    return steps;
}

int main()
{
    AOC::print_header("05");

    auto numbers = AOC::convert_strings<int32_t>(AOC::read_lines("input.txt"));

    std::cout << "Solution for part one: " << part_one(numbers) << std::endl;
    std::cout << "Solution for part two: " << part_two(numbers) << std::endl;

}
