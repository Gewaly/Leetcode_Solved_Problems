/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructRecursive(grid, 0, 0, grid.size());
    }
    
private:
    Node* constructRecursive(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) {
            return new Node(grid[x][y] == 1, true);
        }
        
        Node* node = new Node();
        
        Node* topLeft = constructRecursive(grid, x, y, size/2);
        Node* topRight = constructRecursive(grid, x, y + size/2, size/2);
        Node* bottomLeft = constructRecursive(grid, x + size/2, y, size/2);
        Node* bottomRight = constructRecursive(grid, x + size/2, y + size/2, size/2);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            node->isLeaf = true;
            node->val = topLeft->val;
        } else {
            node->topLeft = topLeft;
            node->topRight = topRight;
            node->bottomLeft = bottomLeft;
            node->bottomRight = bottomRight;
        }
        
        return node;
    }
};