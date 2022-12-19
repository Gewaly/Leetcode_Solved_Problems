/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
     int ans=-1003;
    int dfs(TreeNode root){
        if(root==null) return 0;
        int x=dfs(root.left);
        int y=dfs(root.right);
        ans=Math.max(ans,x+y+root.val);
        return Math.max(0,root.val+Math.max(x,y));
    }
    public int maxPathSum(TreeNode root) {
           dfs(root);
        return ans;
    }
}