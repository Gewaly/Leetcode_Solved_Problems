class Solution {
public:
    TreeNode* result;
    int find_depth(TreeNode* root, int depth) {
        if (root == nullptr) return depth;
        return max(find_depth(root->left, depth + 1), find_depth(root->right, depth + 1));
    }
    void find_subtree(TreeNode* root) {
        int left = find_depth(root->left, 0);
        int right = find_depth(root->right, 0);
        if (left == right) {
            result = root;
            return;
        }
        else if (left > right) {
            result = root;
            find_subtree(root->left);
        }
        else {
            result = root;
            find_subtree(root->right);
        }
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        find_subtree(root);
        return result;
    }
};