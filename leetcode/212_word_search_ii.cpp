//
//  212_word_search_ii.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 07.10.2023.
//

#include <string>
#include <vector>

class Node {
public:
    Node* nodes[26];
    std::string word;
    
    Node() : word("") {
        for (std::size_t i = 0; i < 26; ++i) {
            nodes[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root;
    
    Trie() : root(new Node()) { }
    
    void addWord(const std::string& word) {
        Node* parent = root;
        for (const char& letter : word) {
            if (!parent->nodes[letter - 'a']) {
                parent->nodes[letter - 'a'] = new Node();
            }
            parent = parent->nodes[letter - 'a'];
        }
        parent->word = word;
    }
    
    void search(std::vector<std::vector<char>>& board, std::vector<std::string>& answer, Node* node, std::size_t i, std::size_t j) {
        if (i >= board.size() || j >= board[0].size() || board[i][j] == ' ' || !node->nodes[board[i][j] - 'a']) {
            return;
        }
        node = node->nodes[board[i][j] - 'a'];
        char replace = board[i][j];
        board[i][j] = ' ';
        if (!node->word.empty()) {
            answer.push_back(node->word);
            node->word.clear();
        }
        search(board, answer, node, i - 1, j);
        search(board, answer, node, i, j - 1);
        search(board, answer, node, i + 1, j);
        search(board, answer, node, i, j + 1);
        board[i][j] = replace;
    }
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        Trie trie = Trie();
        for (const std::string& word : words) {
            trie.addWord(word);
        }
        std::vector<std::string> answer;
        for (std::size_t i = 0; i < board.size(); ++i) {
            for (std::size_t j = 0; j < board[0].size(); ++j) {
                trie.search(board, answer, trie.root, i, j);
            }
        }
        
        return answer;
    }
};

//std::vector<std::vector<char>> board = {
//    {'o', 'a', 'a', 'n'},
//    {'e', 't', 'a', 'e'},
//    {'i', 'h', 'k', 'r'},
//    {'i', 'f', 'l', 'v'}
//};
//std::vector<std::string> words = {"oath","pea","eat","rain"};
//Helper().PrintVector(Solution().findWords(board, words));
//board = {
//    {'a', 'b'},
//    {'c', 'd'}
//};
//words = {"abcb"};
//Helper().PrintVector(Solution().findWords(board, words));
//board = {
//    {'a', 'b', 'c'},
//    {'a', 'e', 'd'},
//    {'a', 'f', 'g'}
//};
//words = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
//Helper().PrintVector(Solution().findWords(board, words));
