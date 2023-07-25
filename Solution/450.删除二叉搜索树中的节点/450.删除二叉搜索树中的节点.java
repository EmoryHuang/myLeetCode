/*
 * @Descroption: LeetCode 450. 删除二叉搜索树中的节点
 * @Author: EmoryHuang
 * @Date: 2023-07-15 16:35:25
 * @Method:
 * 根据二叉搜索树性质遍历
 * 如果目标节点大于当前节点值，则去右子树中删除，否则去左子树中删除
 * 如果目标节点就是当前节点：
 * 1. 其无左子：其右子顶替其位置，删除了该节点
 * 2. 其无右子：其左子顶替其位置，删除了该节点
 * 3. 其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置
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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
        } else if (root.val < key) {
            root.right = deleteNode(root.right, key);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                TreeNode tmp = root.right;
                // 右孩子的最左节点
                while (tmp.left != null) {
                    tmp = tmp.left;
                }
                tmp.left = root.left;
                root = root.right;
            }
        }
        return root;
    }
}