/*
 * @Description: LeetCode 437. 路径总和 III
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:20:52
 * @解题思路:
 * 2个dfs，分别对每个节点的子树计算路径和
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
        dfsNode(root, targetSum);
        return ans;
    }

    void dfsNode(TreeNode node, int targetSum) {
        if (node == null) {
            return;
        }
        dfsSub(node, node.val, targetSum);
        dfsNode(node.left, targetSum);
        dfsNode(node.right, targetSum);
    }

    void dfsSub(TreeNode node, long val, int targetSum) {
        if (val == targetSum) {
            ans++;
        }
        if (node.left != null) {
            dfsSub(node.left, node.left.val + val, targetSum);
        }
        if (node.right != null) {
            dfsSub(node.right, node.right.val + val, targetSum);
        }
    }
}