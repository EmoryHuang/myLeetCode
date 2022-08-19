/*
 * @Descroption: LeetCode 116. 填充每个节点的下一个右侧节点指针
 * @Author: EmoryHuang
 * @Date: 2021-05-14 16:25:25
 * @解题思路: 采用二叉树层序遍历的思想
 * 若当前结点不是该层的最后一个结点，则令 node->next = q.front()
 * 若当前结点是该层的最后一个结点，则令 node->next = NULL
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