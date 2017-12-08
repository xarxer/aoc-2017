#include <vector>
#include <iostream>
#include <algorithm>

#include <AOCUtils/io.h>

bool is_anagram(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

uint32_t part_one(std::vector<std::vector<std::string>> const& phrases)
{
    uint32_t valid_phrases = 0;

    for(auto const& sub_vector : phrases) {

        bool is_valid = true;

        for(auto it = sub_vector.cbegin(); it != sub_vector.cend() && is_valid; it++) {
            for(auto comp = std::next(it); comp != sub_vector.cend(); comp++) {
                if((*it).compare(*comp) == 0) {
                    is_valid = false;
                    break;
                }
            }
        }

        valid_phrases += is_valid ? 1 : 0;
    }

    return valid_phrases;
}

uint32_t part_two(std::vector<std::vector<std::string>> const& phrases)
{
    uint32_t valid_phrases = 0;

    for(auto const& sub_vector : phrases) {

        bool is_valid = true;

        for(auto it = sub_vector.cbegin(); it != sub_vector.cend() && is_valid; it++) {
            for(auto comp = std::next(it); comp != sub_vector.cend(); comp++) {
                if(is_anagram(*it, *comp)) {
                    is_valid = false;
                    break;
                }
            }
        }

        valid_phrases += is_valid ? 1 : 0;
    }

    return valid_phrases;
}

int main()
{
    AOC::print_header("04");
    std::vector<std::vector<std::string>> phrases;

    auto lines = AOC::read_lines("input.txt");

    for(auto const& line : lines) {
        phrases.push_back(AOC::split_string(line));
    }

    std::cout << "Solution for part one: " << part_one(phrases) << std::endl;
    std::cout << "Solution for part two: " << part_two(phrases) << std::endl;

}
