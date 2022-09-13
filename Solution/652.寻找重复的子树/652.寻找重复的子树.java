/*
 * @Descroption: LeetCode 652. 寻找重复的子树
 * @Author: EmoryHuang
 * @Date: 2022-09-05 10:41:30
 * @Method:
 * dfs
 * 将子树进行序列化表示，作为key，并存入哈希表
 * 若出现相同key则认为出现重复子树
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
    Map<String, TreeNode> map = new HashMap<String, TreeNode>();
    Set<TreeNode> ans = new HashSet<TreeNode>();

    public String dfs(TreeNode node) {
        if (node == null)
            return "";
        StringBuilder sb = new StringBuilder();
        sb.append(node.val).append('(');
        sb.append(dfs(node.left)).append(")(");
        sb.append(dfs(node.right)).append(')');
        String key = sb.toString();
        if (map.containsKey(key)) {
            ans.add(map.get(key));
        } else {
            map.put(key, node);
        }
        return key;

    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        dfs(root);
        return new ArrayList<TreeNode>(ans);
    }
}