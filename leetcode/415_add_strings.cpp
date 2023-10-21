// Создано 21.10.2023
#include <string>

class Solution {
public:
    std::string shrink(const std::string& num) {
        std::size_t i = 0;
        while (i < num.size() && num[i] == '0') {
            ++i;
        }
        return i == num.size() ? "0" : num.substr(i);
    }

    std::string addStrings(std::string num1, std::string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        if (num1.length() != num2.length()) {
            while (num1.length() < num2.length()) {
                num1.push_back('0');
            }
            while (num1.length() > num2.length()) {
                num2.push_back('0');
            }
        }
        std::size_t n = num1.length();
        std::string answer;
        bool add = false;
        for (std::size_t i = 0; i < n; ++i) {
            int temp = 0;
            if (add) {
                ++temp;
            }
            add = false;
            temp += num1[i] - '0';
            temp += num2[i] - '0';
            if (temp >= 10) {
                add = true;
                temp -= 10;
            }
            answer.push_back('0' + temp);
        }
        if (add) {
            answer.push_back('1');
        }
        std::reverse(answer.begin(), answer.end());
        return shrink(answer);
    }
};