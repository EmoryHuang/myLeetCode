/*
 * @Descroption: LeetCode 1161. 最大层内元素和
 * @Author: EmoryHuang
 * @Date: 2023-07-15 16:17:12
 * @Method:
 * 二叉树层序遍历
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
    public int maxLevelSum(TreeNode root) {
        int max = Integer.MIN_VALUE;
        int layer = 0, ans = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int len = q.size(), sum = 0;
            layer++;
            for (int i = 0; i < len; i++) {
                TreeNode cur = q.poll();
                sum += cur.val;
                if (cur.left != null) {
                    q.offer(cur.left);
                }
                if (cur.right != null) {
                    q.offer(cur.right);
                }
            }
            if (sum > max) {
                max = sum;
                ans = layer;
            }
        }
        return ans;
    }
}