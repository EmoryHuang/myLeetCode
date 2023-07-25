/*
 * @Descroption: LeetCode 872. 叶子相似的树
 * @Author: EmoryHuang
 * @Date: 2023-07-15 10:35:15
 * @Method:
 * dfs分别记录两棵树的叶子节点
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> ls1 = new ArrayList<>();
        if (root1 != null) {
            dfs(root1, ls1);
        }

        List<Integer> ls2 = new ArrayList<>();
        if (root2 != null) {
            dfs(root2, ls2);
        }
        return ls1.equals(ls2);
    }

    void dfs(TreeNode root, List<Integer> ls) {
        if (root.left == null && root.right == null) {
            ls.add(root.val);
        } else {
            if (root.left != null) {
                dfs(root.left, ls);
            }
            if (root.right != null) {
                dfs(root.right, ls);
            }
        }
    }
}