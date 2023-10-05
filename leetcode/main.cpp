#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "127_word_ladder.cpp"

int main() {
    std::string startGene = "hit";
    std::string endGene = "cog";
    std::vector<std::string> bank = {"hot","dot","dog","lot","log","cog"};
    std::cout << Solution().ladderLength(startGene, endGene, bank) << std::endl;
    startGene = "hit";
    endGene = "cog";
    bank = {"hot","dot","dog","lot","log"};
    std::cout << Solution().ladderLength(startGene, endGene, bank) << std::endl;
}
