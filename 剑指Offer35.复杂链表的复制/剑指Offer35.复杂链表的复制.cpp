/*
 * @Descroption: 剑指 Offer 35. 复杂链表的复制
 * @Author: EmoryHuang
 * @Date: 2021-07-23 19:20:53
 * @解题思路:
 * 回溯 + 哈希表
 * 使用哈希表存储出现过的节点
 * 如果当前节点已经被拷贝过，那么就直接返回
 * 如果当前节点的 next 和 random 都没有被创建，就递归地进行创建
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    map<Node*, Node*> ans;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (ans.count(head) != 0) return ans[head];
        Node* copy = new Node(head->val);
        ans[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};