#include <iostream>
#include <vector>
//#include "helper_things.cpp"
#include "211_design_add_and_search_words_data_structure.cpp"

int main() {
    WordDictionary wordDictionary = WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    std::cout << wordDictionary.search("pad"); // return False
    std::cout << wordDictionary.search("bad"); // return True
    std::cout << wordDictionary.search(".ad"); // return True
    std::cout << wordDictionary.search("b.."); // return True
}
