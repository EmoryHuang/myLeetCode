/*
 * @Descroption: LeetCode 687. 最长同值路径
 * @Author: EmoryHuang
 * @Date: 2022-09-02 09:20:50
 * @Method:
 * dfs
 * 分别获取左右节点的最长同值路径
 * 若左孩子非空并且左孩子的值等于当前节点的值，则更新长度加1，右孩子同理
 * 维护ans, ans = max(ans, leftmax + rightmax)
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    int ans;

    int dfs(TreeNode node) {
        if (node == null)
            return 0;
        int left = dfs(node.left), right = dfs(node.right);
        int leftmax = 0, rightmax = 0;
        if (node.left != null && node.left.val == node.val)
            leftmax = left + 1;
        if (node.right != null && node.right.val == node.val)
            rightmax = right + 1;
        ans = Math.max(ans, leftmax + rightmax);
        return Math.max(leftmax, rightmax);
    }

    public int longestUnivaluePath(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }
}