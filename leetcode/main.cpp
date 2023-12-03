#include <iostream>
#include <vector>
#include <string>
#include "76_minimum_window_substring.cpp"

int main() {
   std::string s = "ADOBECODEBANC";
   std::string t = "ABC";
   std::cout << Solution().minWindow(s, t) << std::endl;

   s = "a";
   t = "a";
   std::cout << Solution().minWindow(s, t) << std::endl;

   s = "a";
   t = "aa";
   std::cout << Solution().minWindow(s, t) << std::endl;
} 
