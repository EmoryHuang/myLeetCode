/*
 * @Descroption: ��ָ Offer 07. �ؽ�������
 * @Author: EmoryHuang
 * @Date: 2021-06-28 19:56:00
 * @����˼·:
 * ���������������������ؽ�������
 * ���õݹ�ķ���
 * �������������ߵĽڵ��Ǹ��ڵ㣬
 * Ȼ���ٵ�����������ҵ����ڵ��λ�ã�������������һ��Ϊ��
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    unordered_map<int, int> map;
    TreeNode* build(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l,
                    int in_r) {
        if (pre_l > pre_r || in_l > in_r) return nullptr;
        // ���ڵ���ǰ������е�λ��
        int pre_root = pre_l;
        // ���ڵ�����������е�λ��
        int in_root = map[preorder[pre_root]];
        TreeNode* root = new TreeNode(preorder[pre_root]);
        // �������ڵ����
        int left_size = in_root - in_l;

        root->left = build(preorder, pre_l + 1, pre_l + left_size, inorder, in_l, in_root - 1);
        root->right = build(preorder, pre_l + left_size + 1, pre_r, inorder, in_root + 1, in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};