//
//  127_word_ladder.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 05.10.2023.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        int iterations = 0;
        std::unordered_set<std::string> set(wordList.begin(), wordList.end());
        set.insert(beginWord);
        std::vector<char> chars;
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            chars.push_back(letter);
        }
        
        std::queue<std::string> words;
        words.push(beginWord);
        
        std::size_t n = beginWord.size();
        while (!words.empty()) {
            std::size_t current_iter_size = words.size();
            ++iterations;
            
            while (current_iter_size--) {
                std::string current = words.front();
                words.pop();
                
                if (current == endWord) {
                    return iterations;
                }
                
                for (std::size_t i = 0; i < n; ++i) {
                    char replace = current[i];
                    for (const char& ch : chars) {
                        current[i] = ch;
                        if (set.find(current) != set.end()) {
                            words.push(current);
                            set.erase(current);
                        }
                    }
                    current[i] = replace;
                }
            }
        }
        return 0;
    }
};
