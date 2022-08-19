/*
 * @Descroption: LeetCode 116. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
 * @Author: EmoryHuang
 * @Date: 2021-05-14 16:25:25
 * @����˼·: ���ö��������������˼��
 * ����ǰ��㲻�Ǹò�����һ����㣬���� node->next = q.front()
 * ����ǰ����Ǹò�����һ����㣬���� node->next = NULL
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                if (i != n - 1)
                    node->next = q.front();
                else
                    node->next = NULL;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};