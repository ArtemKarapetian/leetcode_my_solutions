#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "212_word_search_ii.cpp"

int main() {
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    Helper().PrintVector(Solution().findWords(board, words));
    board = {
        {'a', 'b'},
        {'c', 'd'}
    };
    words = {"abcb"};
    Helper().PrintVector(Solution().findWords(board, words));
    board = {
        {'a', 'b', 'c'},
        {'a', 'e', 'd'},
        {'a', 'f', 'g'}
    };
    words = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
    Helper().PrintVector(Solution().findWords(board, words));
}
