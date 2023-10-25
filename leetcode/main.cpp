#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "39_combination_sum.cpp"

int main() {
    std::vector<int> nums{2, 3, 7};
    Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 7));
    nums = {2, 3, 5};
    Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 8));
    nums = {2};
    Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 1));
} 
