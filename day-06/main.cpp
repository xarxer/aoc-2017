#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

#include <AOCUtils/io.h>

using namespace std::chrono;

static microseconds::rep needle_time = 0;
static microseconds::rep dist_time = 0;

// TODO: This need some serious optimization
bool vector_has_vector(aoc::vector2d<uint32_t> const& haystack, std::vector<uint32_t> needle)
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bool result = std::any_of(haystack.cbegin(), haystack.cend(), [&](std::vector<uint32_t> const& sub_vector) {
        return sub_vector == needle;
    });
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    needle_time += duration_cast<microseconds>(t2 - t1).count();

    return result;
}

std::vector<uint32_t> redistribute(std::vector<uint32_t> const& banks)
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::vector<uint32_t> distributed = banks;

    auto it = std::max_element(distributed.begin(), distributed.end());

    uint32_t value = *it;
    *it = 0;

    while(value > 0) {
        it = std::next(it) == distributed.end() ? distributed.begin() : std::next(it);
        (*it)++;
        value--;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    dist_time += duration_cast<microseconds>(t2 - t1).count();

    return distributed;
}

uint32_t part_one(std::vector<uint32_t> numbers)
{
    uint32_t steps = 0;

    std::vector<uint32_t>   current_state = numbers;
    aoc::vector2d<uint32_t> permutations;

    while(vector_has_vector(permutations, current_state) == false) {
        permutations.push_back(current_state);
        current_state = redistribute(current_state);

        steps++;
    }


    return steps;
}

uint32_t part_two(std::vector<uint32_t> numbers)
{
    uint32_t steps = 0;

    return steps;
}

int main()
{
    microseconds::rep x;

    aoc::print_header("06");

    auto numbers = aoc::convert_strings<uint32_t>(aoc::split_string(aoc::read_line("input.txt")));
    //std::vector<uint32_t> numbers { 0, 2, 7, 0 };

    std::cout << "Solution for part one: " << part_one(numbers) << std::endl;
    std::cout << "Solution for part two: " << part_two(numbers) << std::endl;

    std::cout << "Needle took: " << needle_time << " microseconds" << std::endl;
    std::cout << "Dist took  : " << dist_time << " microseconds" << std::endl;

}
