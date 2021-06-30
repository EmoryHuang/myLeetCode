/*
 * @Descroption: LeetCode 297. 二叉树的序列化与反序列化
 * @Author: EmoryHuang
 * @Date: 2021-06-30 19:18:00
 * @解题思路:
 * DFS
 * 采用层序遍历方法
 * 用 # 标记空
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
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                encode += to_string(node->val) + ' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                encode += "# ";
            }
        }
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string val;
        ss >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (ss >> val) {
            auto node = q.front();
            q.pop();
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            ss >> val;
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));