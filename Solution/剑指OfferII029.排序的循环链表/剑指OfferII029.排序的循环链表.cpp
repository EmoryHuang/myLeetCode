/*
 * @Descroption: 剑指 Offer II 029. 排序的循环链表
 * @Author: EmoryHuang
 * @Date: 2022-06-18 09:09:30
 * @Method:
 * 遍历循环列表，比较元素的值并插入到合适的位置，需要注意边界条件。
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        // 若 head 为空，则直接插入
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        // 若只有一个节点，则直接插入
        if (head->next == head) {
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        // 寻找插入位置
        Node* cur = head;
        while (cur->next != head) {
            if (cur->val <= insertVal && insertVal <= cur->next->val) break;
            if (cur->val > cur->next->val)
                if (insertVal > cur->val || insertVal < cur->next->val) break;
            cur = cur->next;
        }
        // 插入
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};