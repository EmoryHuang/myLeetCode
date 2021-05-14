/*
 * @Descroption: LeetCode 82. 删除排序链表中的重复元素 II
 * @Author: EmoryHuang
 * @Date: 2021-03-20 20:22:36
 * @解题思路: 基本思路与[83. 删除排序链表中的重复元素]
 * 不同的是需要删除所有元素，因此需要设置一个前驱指针，以便删除所有重复元素
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
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);  //头指针
        dummy->next = head;
        ListNode *p = head, *pre = dummy;
        while (p && p->next) {
            if (p->val == p->next->val) {  //如果当前元素与下一个元素相同
                while (p->next && p->val == p->next->val) {  //直到不相同为止
                    ListNode* temp = p;
                    p = p->next;  //当前元素后移
                    delete temp;
                }
                ListNode* del = p;    //删除当前元素
                pre->next = p->next;  //更新连接
                p = p->next;
                delete del;
            } else {  //不相同则都后移
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};