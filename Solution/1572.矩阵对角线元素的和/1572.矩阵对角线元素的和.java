/*
 * @Description: LeetCode 1572. 矩阵对角线元素的和
 * @Author: EmoryHuang
 * @Date: 2023-08-11 09:12:30
 * @解题思路:
 * 简单题，遍历矩阵
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
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
}