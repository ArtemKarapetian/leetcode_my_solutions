// 25.10.2023
#include <vector>


class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int> > answer;
        std::vector<int> current;
        solve(answer, candidates, current, 0, target);
        return answer;
    }

    void solve(std::vector<std::vector<int> >& answer, std::vector<int>& candidates, std::vector<int>& current, std::size_t begin, int to_target) {
        if (to_target < 0) {
            return;
        }
        if (!to_target) {
            answer.push_back(current);
        }
        for (std::size_t i = begin; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            solve(answer, candidates, current, i, to_target - candidates[i]);
            current.pop_back();
        }
    }
};

// std::vector<int> nums{2, 3, 7};
//     Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 7));
//     nums = {2, 3, 5};
//     Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 8));
//     nums = {2};
//     Helper().PrintVectorVectorInt(Solution().combinationSum(nums, 1));