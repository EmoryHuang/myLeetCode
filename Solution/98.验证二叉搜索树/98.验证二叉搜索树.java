/*
 * @Description: LeetCode 98. 验证二叉搜索树
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:01:15
 * @解题思路:
 * 根据二叉搜索树的性质递归
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
    public boolean isValidBST(TreeNode root) {
        return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    boolean dfs(TreeNode node, long left, long right) {
        if (node == null) {
            return true;
        }
        if (node.val <= left || node.val >= right) {
            return false;
        }
        return dfs(node.left, left, node.val) && dfs(node.right, node.val, right);
    }
}