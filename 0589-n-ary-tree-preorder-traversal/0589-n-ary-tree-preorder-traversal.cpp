/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre(Node* node, vector<int>* ans) {
        ans->push_back(node->val);
        for (Node* child : node->children)
            pre(child, ans);
    }
    vector<int> preorder(Node* root) {
      vector<int> ans;
        if (root) pre(root, &ans);
        return ans;
    }
};