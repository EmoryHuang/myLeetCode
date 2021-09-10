/*
 * @Descroption: LeetCode 590. N 叉树的后序遍历
 * @Author: EmoryHuang
 * @Date: 2021-05-29 15:09:00
 * @解题思路:
 * 方法一：递归
 *
 * 方法二：迭代
 * 使用栈得到前序遍历，需要保证栈顶的节点就是当前遍历到的节点
 *
 * 修改前序遍历，然后反转即可
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
    // vector<int> postorder(Node* root) {
    //     if (root == nullptr) return ans;
    //     for (auto child : root->children) postorder(child);
    //     ans.push_back(root->val);
    //     return ans;
    // }

    // 方法二：迭代
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