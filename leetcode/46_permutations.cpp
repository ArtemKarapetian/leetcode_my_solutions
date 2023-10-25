//
//  46_permutations.cpp
//  leetcode
//
//  Created by Нелли Карапетян on 11.10.2023.
//

#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int> > answer;
        solve(answer, 0, nums);
        return answer;
    }
    
    void solve(std::vector<std::vector<int>>& answer, std::size_t begin, std::vector<int>& nums) {
        if (begin == nums.size()) {
            answer.push_back(nums);
            return;
        }
        for (std::size_t i = begin; i < nums.size(); ++i) {
            std::swap(nums[begin], nums[i]);
            solve(answer, begin + 1, nums);
            std::swap(nums[begin], nums[i]);
        }
    }
};
// std::vector<int> nums{1, 2, 3};
//     Helper().PrintVectorVectorInt(Solution().permute(nums));
//     nums = {0, 1};
//     Helper().PrintVectorVectorInt(Solution().permute(nums));
//     nums = {1};
//     Helper().PrintVectorVectorInt(Solution().permute(nums));