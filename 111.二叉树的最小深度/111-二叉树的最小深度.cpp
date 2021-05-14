class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        if (!root->left && !root->right) return 1;
        int ans = INT_MAX;
        if (root->left) ans = min(ans, minDepth(root->left));
        if (root->right) ans = min(ans, minDepth(root->right));
        return ans + 1;
    }
};