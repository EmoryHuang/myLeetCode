/*
 * @Descroption: LeetCode 623. 在二叉树中增加一行
 * @Author: EmoryHuang
 * @Date: 2022-08-04 09:08:05
 * @Method:
 * 层序遍历，遍历到 depth - 1 层时，添加新的节点
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

  public TreeNode addOneRow(TreeNode root, int val, int depth) {
    if (depth == 1) {
      TreeNode newNode = new TreeNode(val);
      newNode.left = root;
      return newNode;
    }
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    int cur_depth = 1;
    while (!q.isEmpty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        TreeNode node = q.poll();
        if (cur_depth == depth - 1) {
          TreeNode newNode = new TreeNode(val);
          newNode.left = node.left;
          node.left = newNode;
          newNode = new TreeNode(val);
          newNode.right = node.right;
          node.right = newNode;
        }
        if (node.left != null) q.offer(node.left);
        if (node.right != null) q.offer(node.right);
      }
      cur_depth++;
    }
    return root;
  }
}
