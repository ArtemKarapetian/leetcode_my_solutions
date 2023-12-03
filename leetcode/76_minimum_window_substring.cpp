#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> letters;
        for (const char& letter : t) {
            letters[letter]++;
        }

        std::unordered_set<char> letters_in_current_substring;
        auto left_pointer = s.begin();
        auto right_pointer = s.begin();
        std::string answer = s + "a";
        while (right_pointer != s.end()) {
            if (letters.find(*right_pointer) == letters.end()) {
                ++right_pointer;
                continue;
            }
            letters[*right_pointer]--;
            if (!letters[*right_pointer]) {
                letters_in_current_substring.insert(*right_pointer);
            }
            if (letters_in_current_substring.size() != letters.size()) {
                ++right_pointer;
                continue;
            }
            while (left_pointer <= right_pointer) {
                if (letters.find(*left_pointer) == letters.end()) {
                    ++left_pointer;
                    continue;
                }
                if (letters[*left_pointer] == 0) {
                    break;
                }
                letters[*left_pointer]++;
                ++left_pointer;
            }
            if (right_pointer - left_pointer < answer.length()) {
                answer = std::string(left_pointer, right_pointer + 1);
            }
            ++right_pointer;
        }
        return answer.length() > s.length() ? "" : answer;
    }
};
