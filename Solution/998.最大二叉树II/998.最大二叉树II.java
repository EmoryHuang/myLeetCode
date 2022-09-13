/*
 * @Descroption: LeetCode 998. 最大二叉树 II
 * @Author: EmoryHuang
 * @Date: 2022-08-30 09:13:49
 * @Method:
 * 遍历右子节点
 * 若插入值 val 大于根节点，则将根节点作为其左孩子
 * 否则，将其插入根节点的右孩子进行遍历
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);
        if (root.val < val) {
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        } else {
            root.right = insertIntoMaxTree(root.right, val);
            return root;
        }
    }
}