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
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
    var sum = 0;
    if (root == null)  return sum;
    

    if (root.val > L) sum += rangeSumBST(root.left, L, R);
    
    if (root.val <= R && root.val >= L) sum += root.val;
    
    if (root.val < R)  sum += rangeSumBST(root.right, L, R);    
    
    
    return sum;
};