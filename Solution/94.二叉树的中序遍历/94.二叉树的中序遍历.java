/*
 * @Description: LeetCode 94. 二叉树的中序遍历
 * @Author: EmoryHuang
 * @Date: 2023-08-09 14:37:15
 * @解题思路:
 * 方法一：递归
 * 方法二：迭代
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        // 方法一：递归
        // inorder(root, ans);

        // 方法二：迭代
        Deque<TreeNode> stack = new LinkedList<>();
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            ans.add(root.val);
            root = root.right;
        }
        return ans;
    }

    void inorder(TreeNode root, List<Integer> ans) {
        if (root != null) {
            inorder(root.left, ans);
            ans.add(root.val);
            inorder(root.right, ans);
        }
    }
}