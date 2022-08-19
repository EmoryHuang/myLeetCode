/*
 * @Descroption: LeetCode 589. N 叉树的前序遍历
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:58:00
 * @解题思路:
 * 方法一：递归
 *
 * 方法二：迭代
 * 使用栈得到前序遍历，需要保证栈顶的节点就是当前遍历到的节点
 * 具体来说，所有子节点逆序入栈
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    // 方法一：递归
    // vector<int> ans;
    // vector<int> preorder(Node* root) {
    //     if (root == nullptr) return ans;
    //     ans.push_back(root->val);
    //     for (auto child : root->children) preorder(child);
    //     return ans;
    // }

    // 方法二：迭代
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            ans.push_back(node->val);
            int n = (node->children).size();
            for (int i = n - 1; i >= 0; i--)
                if (node->children[i]) s.push(node->children[i]);
        }
        return ans;
    }
};