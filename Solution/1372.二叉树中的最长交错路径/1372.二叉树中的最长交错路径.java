/*
 * @Descroption: LeetCode 1372. 二叉树中的最长交错路径
 * @Author: EmoryHuang
 * @Date: 2023-07-15 15:45:25
 * @Method:
 * dfs
 * 对于每个节点分别考虑左右子节点的情况
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
    public int longestZigZag(TreeNode root) {
        return Math.max(dfs(root.left, 1, true), dfs(root.right, 1, false)) - 1;
    }

    int dfs(TreeNode root, int num, boolean left) {
        if (root == null) {
            return num;
        }
        if (left) {
            return Math.max(dfs(root.left, 1, true), dfs(root.right, num + 1, false));
        } else {
            return Math.max(dfs(root.left, num + 1, true), dfs(root.right, 1, false));
        }
    }
}