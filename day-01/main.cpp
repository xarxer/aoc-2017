#include <vector>
#include <iostream>

#include <AOCUtils/io.h>

uint32_t part_one(std::vector<uint32_t> const& numbers)
{
    uint32_t sum = 0;

    for(auto it = numbers.cbegin(), comp = std::next(it); it != numbers.cend(); it++) {
        comp = std::next(it) == numbers.cend() ? numbers.cbegin() : std::next(it);
        sum += *it == *comp ? *it : 0;
    }

    return sum;
}

uint32_t part_two(std::vector<uint32_t> const& numbers)
{
    uint32_t sum = 0;
    std::ptrdiff_t step_size = numbers.size() / 2;

    for(auto it = numbers.cbegin(); it != numbers.cend(); it++) {
        auto comp = std::distance(it, numbers.cend()) <= step_size ?
                    std::next(numbers.cbegin(), step_size - std::distance(it, numbers.cend())) :
                    std::next(it, step_size);

        sum += *it == *comp ? *it : 0;
    }

    return sum;
}

int main()
{
    aoc::print_header("01");

    auto str = aoc::read_line("input.txt");
    std::vector<uint32_t> numbers;

    // Convert each char to an int
    for(char const& c : str) {
        numbers.push_back(static_cast<uint32_t>(std::stoul(std::string(1, c))));
    }

    std::cout << "Solution for part one: " << part_one(numbers) << std::endl;
    std::cout << "Solution for part two: " << part_two(numbers) << std::endl;

}
