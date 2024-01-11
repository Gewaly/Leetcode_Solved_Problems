/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function(root) {
    let min = Infinity, max = -Infinity;
    let diff = 0;

    const dfs = function (node, min, max) {
        if (!node) return;

        if (node.val < min) min = node.val;
        if (node.val > max) max = node.val;
        if (max - min > diff) diff = max - min;

        dfs(node.left, min, max);
        dfs(node.right, min, max);
    };

    dfs(root, min, max);

    return diff;
};