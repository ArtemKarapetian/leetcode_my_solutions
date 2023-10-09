//
//  77_combinations.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 09.10.2023.
//

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> answer;
        std::vector<int> current(k, 0);
        int i = 0;
        while (i >= 0) {
            ++current[i];
            if (current[i] > n) {
                --i;
            }
            else if (i == k - 1) {
                answer.push_back(current);
            }
            else {
                ++i;
                current[i] = current[i - 1];
            }
        }
        return answer;
    }
};

//class Solution {
//public:
//    std::vector<std::vector<int>> combine(int n, int k) {
//        std::vector<std::vector<int>> answer;
//        std::vector<int> current;
//        solve(n, k, 1, answer, current);
//        return answer;
//    }
//    
//    void solve(int n, int k, int begin, std::vector<std::vector<int>>& answer, std::vector<int>& current) {
//        if (!k) {
//            answer.push_back(current);
//        }
//        for (int i = begin; i <= n; ++i) {
//            current.push_back(i);
//            solve(n, k - 1, i + 1, answer, current);
//            current.pop_back();
//        }
//    }
//};
//
//Helper().PrintVectorVectorInt(Solution().combine(4, 2));
//Helper().PrintVectorVectorInt(Solution().combine(1, 1));
