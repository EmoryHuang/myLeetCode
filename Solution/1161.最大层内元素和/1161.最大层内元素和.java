/*
 * @Descroption: LeetCode 1161. 最大层内元素和
 * @Author: EmoryHuang
 * @Date: 2022-07-31 12:20:24
 * @Method:
 * 并查集
 * 如果 i 是 num 的因数，则 num 和 i、num/i 都属于同一个组件
 * 如果两个正整数满足其中一个正整数是另一个正整数的因数，则这两个正整数属于同一个组件，将这两个正整数的组件合并
 * 之后即可得到最大组件的大小
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

  public int maxLevelSum(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    int max = Integer.MIN_VALUE, depth = 1, ans = 0;
    while (!q.isEmpty()) {
      int size = q.size(), sum = 0;
      for (int i = 0; i < size; i++) {
        TreeNode node = q.poll();
        sum += node.val;
        if (node.left != null) {
          q.offer(node.left);
        }
        if (node.right != null) {
          q.offer(node.right);
        }
      }
      if (sum > max) {
        max = sum;
        ans = depth;
      }
      depth++;
    }
    return ans;
  }
}
