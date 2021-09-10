/*
 * @Descroption: LeetCode 108. 将有序数组转换为二叉搜索树
 * @Author: EmoryHuang
 * @Date: 2021-05-09 16:00:36
 * @解题思路:
 * 以升序序列中的任一个元素作为根节点，以该元素左边的升序序列构建左子树，以该元素右边的升序序列构建右子树，这样得到的树就是一棵二叉搜索树
 * 又因为本题要求高度平衡，因此我们需要选择升序序列的中间元素作为根节点
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode *buildBST(vector<int> &nums, int l, int r) {
        if (r < l) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, l, mid - 1);
        node->right = buildBST(nums, mid + 1, r);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) { return buildBST(nums, 0, nums.size() - 1); }
};