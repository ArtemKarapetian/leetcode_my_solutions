// 29.10.2023
#include <vector>
#include <string>

class Solution {
public:
    const char OPENED_PARENTHESE = '(';
    const char CLOSED_PARENTHESE = ')';

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> answer;
        std::string parentheses;
        solve(answer, parentheses, n, 0);
        return answer;
    }

    // less lines of code.
    void solve(std::vector<std::string>& answer, std::string parentheses, int to_open, int to_close) {
        if (!to_open && !to_close) {
            answer.push_back(parentheses);
            return;
        }
        if (to_open) {
            solve(answer, parentheses + OPENED_PARENTHESE, to_open - 1, to_close + 1);
        }
        if (to_close) {
            solve(answer, parentheses + CLOSED_PARENTHESE, to_open, to_close - 1);
        }
    }

    // less memory complexity.
    // void solve(std::vector<std::string>& answer, std::string& parentheses, int to_open, int to_close) {
    //     if (!to_open && !to_close) {
    //         answer.push_back(parentheses);
    //         return;
    //     }
    //     if (to_open) {
    //         parentheses.push_back(OPENED_PARENTHESE);
    //         solve(answer, parentheses, to_open - 1, to_close + 1);
    //         parentheses.pop_back();
    //     }
    //     if (to_close) {
    //         parentheses.push_back(CLOSED_PARENTHESE);
    //         solve(answer, parentheses, to_open, to_close - 1);
    //         parentheses.pop_back();
    //     }
    // }
};
// Helper<std::string>().PrintVector(Solution().generateParenthesis(3));