/*
 * @Descroption: LeetCode 590. N �����ĺ������
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:09:00
 * @����˼·:
 * ����һ���ݹ�
 *
 * ������������
 * ʹ��ջ�õ�ǰ���������Ҫ��֤ջ���Ľڵ���ǵ�ǰ�������Ľڵ�
 *
 * �޸�ǰ�������Ȼ��ת����
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
    // vector<int> postorder(Node* root) {
    //     if (root == nullptr) return ans;
    //     for (auto child : root->children) postorder(child);
    //     ans.push_back(root->val);
    //     return ans;
    // }

    // ������������
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            ans.push_back(node->val);
            int n = (node->children).size();
            for (int i = 0; i < n; i++)
                if (node->children[i]) s.push(node->children[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};