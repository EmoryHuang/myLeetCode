/*
 * @Description: LeetCode 226. 翻转二叉树
 * @Author: EmoryHuang
 * @Date: 2023-08-09 14:39:45
 * @解题思路:
 * 递归
 */

import java.util.*;

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode tmp = root.right;
        root.right = invertTree(root.left);
        root.left = invertTree(tmp);
        return root;
    }
}