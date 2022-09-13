/*
 * @Descroption: LeetCode 669. 修剪二叉搜索树
 * @Author: EmoryHuang
 * @Date: 2022-09-10 10:38:55
 * @Method:
 * DFS
 * 如果当前节点的值小于 low, 那么说明当前节点及其左子树均不满足，继续对其右子树进行修剪
 * 如果当前节点的值大于 high, 那么说明当前节点及其右子树均不满足，继续对其左子树进行修剪
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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if (root == null)
            return null;
        if (root.val < low)
            return trimBST(root.right, low, high);
        if (root.val > high)
            return trimBST(root.left, low, high);
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
        return root;
    }
}