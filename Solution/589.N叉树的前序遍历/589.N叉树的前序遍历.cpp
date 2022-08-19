/*
 * @Descroption: LeetCode 589. N ������ǰ�����
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:58:00
 * @����˼·:
 * ����һ���ݹ�
 *
 * ������������
 * ʹ��ջ�õ�ǰ���������Ҫ��֤ջ���Ľڵ���ǵ�ǰ�������Ľڵ�
 * ������˵�������ӽڵ�������ջ
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
    // ����һ���ݹ�
    // vector<int> ans;
    // vector<int> preorder(Node* root) {
    //     if (root == nullptr) return ans;
    //     ans.push_back(root->val);
    //     for (auto child : root->children) preorder(child);
    //     return ans;
    // }

    // ������������
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