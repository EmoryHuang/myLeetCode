/*
 * @Descroption: LeetCode 1448. 统计二叉树中好节点的数目
 * @Author: EmoryHuang
 * @Date: 2023-07-15 10:41:01
 * @Method:
 * dfs分别记录路径上的最大值与当前节点比较
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

    public int goodNodes(TreeNode root) {
        dfs(root, root.val);
        return ans;
    }

    void dfs(TreeNode root, int n) {
        if (root.val >= n) {
            ans++;
            n = root.val;
        }
        if (root.left != null) {
            dfs(root.left, n);
        }
        if (root.right != null) {
            dfs(root.right, n);
        }
    }
}