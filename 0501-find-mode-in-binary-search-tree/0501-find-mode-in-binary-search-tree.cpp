/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, std::map<int, int> &count) {
        if (root) {
            if (count.count(root->val)){
                count[root->val] += 1;
            } else {
                count[root->val] = 0;
            }
            dfs(root->right, count);
            dfs(root->left, count);
        }
    }
    vector<int> findMode(TreeNode* root) {
        std::map<int, int> count;
        dfs(root, count);

        int maxValue = std::numeric_limits<int>::lowest();
        std::vector<int> maxKeys;

        for (const auto& pair : count) {
            if (pair.second > maxValue) {
                maxValue = pair.second;
                maxKeys.clear();
            }
            if (pair.second == maxValue) {
                maxKeys.push_back(pair.first);
            }
        }

        return maxKeys;
    }
};