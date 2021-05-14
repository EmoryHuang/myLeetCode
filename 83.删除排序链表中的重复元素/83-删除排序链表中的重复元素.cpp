/*
 * @Descroption: LeetCode 83. 删除排序链表中的重复元素
 * @Author: EmoryHuang
 * @Date: 2021-03-20 19:31:36
 * @解题思路: 链表基础题，记得释放删除节点的内存
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else
                p = p->next;
        }
        return head;
    }
};