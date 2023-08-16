/*
 * @Description: LeetCode 236. 二叉树的最近公共祖先
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:25:05
 * @解题思路:
 * dfs
 * 当遇到节点 p 或 q 时返回
 * 当节点 p,q 在节点 root 的异侧时，节点 root 即为最近公共祖先
 */

import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        return left == null ? right : left;
    }
}