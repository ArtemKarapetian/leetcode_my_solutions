//
//  46_permutations.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 11.10.2023.
//

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::unordered_set<std::size_t> already_in;
        std::vector<int> current;
        solve(already_in, answer, current, nums);
        return answer;
    }
    
    void solve(std::unordered_set<std::size_t>& already_in, std::vector<std::vector<int>>& answer, std::vector<int>& current, const std::vector<int>& nums) {
        if (current.size() == nums.size()) {
            answer.push_back(current);
            return;
        }
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (already_in.find(i) == already_in.end()) {
                already_in.insert(i);
                current.push_back(nums[i]);
                solve(already_in, answer, current, nums);
                current.pop_back();
                already_in.erase(i);
            }
        }
    }
};
