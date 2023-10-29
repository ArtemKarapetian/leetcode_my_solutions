// 26.10.2023
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        std::vector<int> columns(n);
        std::vector<int> diag(2 * n - 1);
        std::vector<int> antidiag(2 * n - 1);
        return solve(columns, diag, antidiag, 0);
    }

    int solve(std::vector<int>& columns, std::vector<int>& diag, std::vector<int>& antidiag, int row) {
        std::size_t n = columns.size();
        if (row == n) {
            return 1;
        }
        int answer = 0;
        for (std::size_t col = 0; col < columns.size(); ++col) {
            if (!columns[col] && !diag[col + row] && !antidiag[columns.size() - 1 - col + row]) {
                columns[col] = 1;
                diag[col + row] = 1;
                antidiag[columns.size() - 1 - col + row] = 1;
                answer += solve(columns, diag, antidiag, row + 1);
                columns[col] = 0;
                diag[col + row] = 0;
                antidiag[columns.size() - 1 - col + row] = 0;
            }
        }
        return answer;
    }
};

// std::cout << Solution().totalNQueens(4) << std::endl;
// std::cout << Solution().totalNQueens(1) << std::endl;