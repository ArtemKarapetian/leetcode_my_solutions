#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode* makeTree(std::vector<int> nums, int secret_num = 0) {
        if (nums.empty()) {
            return nullptr;
        }
        auto* root = new TreeNode(nums[0]);
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        std::size_t i = 1;
        while (i < nums.size()) {
            TreeNode* curr_node = nodes.front();
            nodes.pop();
            if (nums[i] != secret_num) {
                curr_node->left = (new TreeNode(nums[i]));
                nodes.push(curr_node->left);
            }
            ++i;
            if (i < nums.size() && nums[i] != secret_num) {
                curr_node->right = (new TreeNode(nums[i]));
                nodes.push(curr_node->right);
            }
            ++i;
        }
        return root;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Helper {
public:
     void PrintVector(std::vector<std::string> vector) {
         for (const std::string& i : vector) {
             std::cout << i << std::endl;
         }
         std::cout << std::endl;
     }
     
     void PrintIntVector(std::vector<int> vector) {
         for (const int& i : vector) {
             std::cout << i << " ";
         }
         std::cout << std::endl;
     }

    void PrintVectorVector(std::vector<std::vector<char>> vector) {
        for (const std::vector<char>& i : vector) {
            for (const char& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    void PrintTree(TreeNode* root) {
        if (!root) {
            return;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            std::size_t n = queue.size();
            while (n--) {
                std::cout << queue.front()->val << " ";
                if (queue.front()->left) {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right) {
                    queue.push(queue.front()->right);
                }
                queue.pop();
            }
            std::cout << std::endl;
        }
    }
};


// Definition for a Node.
//class Node {
//public:
//    int val;
//    std::vector<Node*> neighbors;
//    Node() {
//        val = 0;
//        neighbors = std::vector<Node*>();
//    }
//    Node(int _val) {
//        val = _val;
//        neighbors = std::vector<Node*>();
//    }
//    Node(int _val, std::vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};
