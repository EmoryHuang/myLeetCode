/*
 * @Descroption: LeetCode 662. 二叉树最大宽度
 * @Author: EmoryHuang
 * @Date: 2022-08-27 11:19:08
 * @Method:
 * 采用二叉树层序遍历的思路，记录每层的节点编号
 * 队列中使用int记录编号index
 * 左子树是父节点的 index * 2,右子树是 index * 2 + 1
 * 然后减去 start * 2 便是在该层的节点的数量
 */

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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        int ans = 0;
        Deque<Pair<TreeNode, Integer>> queue = new ArrayDeque<>();
        queue.addLast(new Pair<TreeNode, Integer>(root, 1));
        while (!queue.isEmpty()) {
            int len = queue.size();
            // start是本层起点
            int idx = 0, start = queue.peekFirst().getValue();
            for (int i = 0; i < len; i++) {
                Pair<TreeNode, Integer> tmp = queue.pollFirst();
                TreeNode node = tmp.getKey();
                // 当前节点编号
                idx = tmp.getValue();
                // 减去同一层节点最左边的值
                if (node.left != null)
                    queue.addLast(new Pair<>(node.left, idx * 2 - start * 2));
                if (node.right != null)
                    queue.addLast(new Pair<>(node.right, idx * 2 + 1 - start * 2));
            }
            ans = Math.max(ans, idx - start + 1);
        }
        return ans;
    }
}