//
//  433_minimum_genetic_mutation.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 05.10.2023.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        int iterations = -1;
        std::unordered_set<std::string> set;
        for (const std::string& str : bank) {
            set.insert(str);
        }
        std::vector<char> chars = {'A', 'C', 'G', 'T'};
        std::queue<std::string> genes;
        genes.push(startGene);
        
        while (!genes.empty()) {
            std::size_t current_iter_size = genes.size();
            ++iterations;
            while (current_iter_size--) {
                std::string current = genes.front();
                if (current == endGene) {
                    return iterations;
                }
                for (std::size_t i = 0; i < 8; ++i) {
                    char replace = current[i];
                    for (const char& ch : chars) {
                        if (replace == ch) {
                            continue;
                        }
                        current[i] = ch;
                        if (set.find(current) != set.end()) {
                            genes.push(current);
                            set.erase(current);
                        }
                    }
                    current[i] = replace;
                }
                genes.pop();
            }
        }
        return -1;
    }
};
