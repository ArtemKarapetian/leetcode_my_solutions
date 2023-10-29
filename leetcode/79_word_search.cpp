// 29.10.2023
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    const std::vector<std::vector<int> > MOVEMENTS { {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool exist(std::vector<std::vector<char> >& board, std::string word) {
        if (word.empty()) {
            return false;
        }
        for (std::size_t i = 0; i < board.size(); ++i) {
            for (std::size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    char used = board[i][j];
                    board[i][j] = '*';
                    bool is_word_here = search(board, word, 1, i, j);
                    if (is_word_here) {
                        return true;
                    }
                    board[i][j] = used;
                }
            }
        }
        return false;
    }

    bool search(std::vector<std::vector<char> >& board, const std::string& word, std::size_t index, 
    std::size_t i, std::size_t j) {
        if (index == word.size()) {
            return true;
        }
        for (const auto& move : MOVEMENTS) {
            std::size_t next_i = i + move[0];
            std::size_t next_j = j + move[1];
            if (next_i < board.size() && next_j < board[0].size() && board[next_i][next_j] == word[index]) {
                char used = board[next_i][next_j];
                board[next_i][next_j] = '*';
                bool return_statement = search(board, word, index + 1, next_i, next_j);
                if (return_statement) {
                    return true;
                }
                board[next_i][next_j] = used;
            }
        }
        return false;
    }
};

//    std::vector<std::vector<char> > board = {
//       {'A', 'B', 'C', 'E'}, 
//       {'S', 'F', 'C', 'S'},
//       {'A', 'D', 'E', 'E'}
//    };
//    std::cout << Solution().exist(board, "ABCCED") << std::endl;
//    board = {
//       {'A', 'B', 'C', 'E'}, 
//       {'S', 'F', 'C', 'S'},
//       {'A', 'D', 'E', 'E'}
//    };
//    std::cout << Solution().exist(board, "SEE") << std::endl;
//    board = {
//       {'A', 'B', 'C', 'E'}, 
//       {'S', 'F', 'C', 'S'},
//       {'A', 'D', 'E', 'E'}
//    };
//    std::cout << Solution().exist(board, "ABCB") << std::endl;
//    board = { {'a', 'a'} };
//    std::cout << Solution().exist(board, "aaa") << std::endl;