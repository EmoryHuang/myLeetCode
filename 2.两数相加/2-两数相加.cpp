/*
 * @Descroption: LeetCode 2. 两数相加
 * @Author: EmoryHuang
 * @Date: 2021-03-15 19:30:36
 * @解题思路: 因为链表是倒序的，所以可以直接进行按字符串加减的方法进行计算
 *          如果当前两个链表处相应位置的数字为 n1,n2，进位值为 carry，则它们的和为 n1+n2+carry
 *          答案链表处相应位置的数字为 (n1+n2+carry) % 10，而新的进位值为 (n1+n2+carry) / 10
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int num = n1 + n2 + carry;
            carry = num / 10;  //进位
            num = num % 10;    //下一个数字
            if (!head)         //起始为空
                head = tail = new ListNode(num);
            else {
                tail->next = new ListNode(num);
                tail = tail->next;  //更新尾结点
            }
            if (l1) l1 = l1->next;  //若l1还有值
            if (l2) l2 = l2->next;  //若l2还有值
            if (carry > 0) tail->next = new ListNode(carry);
        }
        return head;
    }
};