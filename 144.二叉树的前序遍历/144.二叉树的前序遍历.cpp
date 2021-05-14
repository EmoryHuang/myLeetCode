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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node=st.top();
            st.pop();
            if(node){
                ans.push_back(node->val);
                st.push(node->right);//ջ�Ǻ���ȳ��������ȼ������ӽڵ�
                st.push(node->left);
            }
        }
        return ans;
    }
};