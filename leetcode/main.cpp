#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "433_minimum_genetic_mutation.cpp"

int main() {
    std::string startGene = "AACCGGTT";
    std::string endGene = "AACCGGTA";
    std::vector<std::string> bank = {"AACCGGTA"};
    std::cout << Solution().minMutation(startGene, endGene, bank) << std::endl;
    startGene = "AACCGGTT";
    endGene = "AAACGGTA";
    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    std::cout << Solution().minMutation(startGene, endGene, bank) << std::endl;
    startGene = "AACCGGTT";
    endGene = "AAACGGTA";
    bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    std::cout << Solution().minMutation(startGene, endGene, bank) << std::endl;
}
