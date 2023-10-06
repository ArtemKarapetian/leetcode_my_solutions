//
//  211_design_add_and_search_words_data_structure.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 05.10.2023.
//

#include <iostream>
#include <string>
#include <queue>

class Node {
public:
    Node* nodes[26];
    bool isWord;
    Node() : isWord(false) {
        for (std::size_t i = 0; i < 26; ++i) {
            nodes[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() : root(new Node()) { }
    
    void addWord(std::string word) {
        Node* parent = root;
        for (const char letter : word) {
            if (!parent->nodes[letter - 'a']) {
                parent->nodes[letter - 'a'] = new Node();
            }
            parent = parent->nodes[letter - 'a'];
        }
        parent->isWord = true;
    }
    
    bool search(std::string word) {
        std::queue<Node*> nodes;
        nodes.push(root);
        for (const char letter : word) {
            std::size_t size = nodes.size();
            if (!size) {
                return false;
            }
            
            while (size--) {
                Node* current = nodes.front();
                nodes.pop();
                if (letter != '.') {
                    if (current->nodes[letter - 'a']) {
                        nodes.push(current->nodes[letter - 'a']);
                    }
                    continue;
                }
                for (Node* node : current->nodes) {
                    if (node) {
                        nodes.push(node);
                    }
                }
            }
        }
        while (!nodes.empty()) {
            Node* current = nodes.front();
            nodes.pop();
            if (current->isWord) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

//WordDictionary wordDictionary = WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//std::cout << wordDictionary.search("pad"); // return False
//std::cout << wordDictionary.search("bad"); // return True
//std::cout << wordDictionary.search(".ad"); // return True
//std::cout << wordDictionary.search("b.."); // return True
