/*
 * @Descroption: LeetCode 430. 扁平化多级双向链表
 * @Author: EmoryHuang
 * @Date: 2021-09-24 11:06:23
 * @Method:
 * dfs
 * 我们需要将 child 指向的链表插入 node 和 node.next 之间
 * 若 child 非空，则优先处理，重新进行链表的连接
 * node 与 child 相连，node.next 与 child_last 相连
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    Node* dfs(Node* node) {
        // 记录链表的最后一个节点
        Node *cur = node, *last;
        while (cur) {
            Node* nxt = cur->next;  // 记录 next
            // 如果存在子节点，那么先处理子节点
            if (cur->child) {
                Node* child_last = dfs(cur->child);
                // 扁平化，将 cur 与 child 连接
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                // 如果 next 非空，就将它与子链表的最后一个节点相连
                if (nxt) {
                    child_last->next = nxt;
                    nxt->prev = child_last;
                }
                last = child_last;
            } else
                last = cur;
            cur = nxt;
        }
        return last;
    }
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};