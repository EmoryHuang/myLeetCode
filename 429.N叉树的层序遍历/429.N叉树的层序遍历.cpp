/*
 * @Descroption: LeetCode 429. N �����Ĳ������
 * @Author: EmoryHuang
 * @Date: 2021-06-01 19:57:00
 * @����˼·:
 * �����������
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                cur.push_back(node->val);
                for (auto ch : node->children) q.push(ch);  // ���ӽڵ����
            }
            ans.push_back(cur);
        }
        return ans;
    }
};