// Created 21.10.2023
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

    std::string multiply(std::string num1, std::string num2) {
        std::string answer(num1.size() + num2.size(), '0');

        for (std::size_t i = num1.size() - 1; i < num1.size(); --i) {
            int current = 0;
            int carry = 0;
            for (std::size_t j = num2.size() - 1; j < num2.size(); --j) {
                current = (answer[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                answer[i + j + 1] = current % 10 + '0';
                carry = current / 10;
            }
            answer[i] = carry + '0';
        }

        return shrink(answer);
    }
};

// std::cout << Solution().multiply("123", "0") << std::endl;
//     std::cout << Solution().multiply("123", "123123") << std::endl;
//     std::cout << Solution().multiply("1223523523452545435123123213213312123123123123123213343453", "1232311241241241212312312312213123213123213213123123123213123123123123123123123213122121312312312123123123123123124124124124") << std::endl;