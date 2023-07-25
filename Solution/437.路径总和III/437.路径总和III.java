/*
 * @Descroption: LeetCode 437. 路径总和 III
 * @Author: EmoryHuang
 * @Date: 2023-07-15 10:58:50
 * @Method:
 * 在 dfs1 中对于每个当前节点，使用 dfs2 搜索以其为根的所有（往下的）路径
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
    int ans = 0;

    public int pathSum(TreeNode root, int targetSum) {
        dfs1(root, targetSum);
        return ans;
    }

    void dfs1(TreeNode root, int targetSum) {
        if (root == null) {
            return;
        }
        dfs2(root, root.val, targetSum);
        dfs1(root.left, targetSum);
        dfs1(root.right, targetSum);
    }

    void dfs2(TreeNode root, long val, int targetSum) {
        if (val == targetSum) {
            ans++;
        }
        if (root.left != null) {
            dfs2(root.left, val + root.left.val, targetSum);
        }
        if (root.right != null) {
            dfs2(root.right, val + root.right.val, targetSum);
        }
    }
}