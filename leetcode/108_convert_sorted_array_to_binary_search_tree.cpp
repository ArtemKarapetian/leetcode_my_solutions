// 29.10.2023
#include "helper_things.cpp"
#include <vector>

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        TreeNode* root = addTree(nums, 0, nums.size());
        return root;
    }

    TreeNode* addTree(std::vector<int>& nums, std::size_t left, std::size_t right) {
        if (left == right) {
            return nullptr;
        }
        if (left + 1 == right) {
            return new TreeNode(nums[left]);
        }
        std::size_t mid = (right + left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = addTree(nums, left, mid);
        node->right = addTree(nums, mid + 1, right);
        return node;
    }
};