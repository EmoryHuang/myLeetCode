/*
 * @Description: LeetCode 108. 将有序数组转换为二叉搜索树
 * @Author: EmoryHuang
 * @Date: 2023-08-11 13:53:20
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
    public TreeNode sortedArrayToBST(int[] nums) {
        return dfs(nums, 0, nums.length - 1);
    }

    TreeNode dfs(int[] nums, int l, int r) {
        if (l > r) {
            return null;
        }
        int mid = l + (r - l) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = dfs(nums, l, mid - 1);
        node.right = dfs(nums, mid + 1, r);
        return node;
    }
}