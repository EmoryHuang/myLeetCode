/*
 * @Descroption: LeetCode 141. ��������
 * @Author: EmoryHuang
 * @Date: 2021-03-25 09:14:36
 * @����˼·:
 * ��������ָ�룬һ��һ������ָ��ÿ��ֻ�ƶ�һ��������ָ��ÿ���ƶ�������
 * �����ָ�뷴����׷����ָ�룬��˵��������Ϊ�������������ָ�뽫��������β����������Ϊ��������
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) return true;
        }
        return false;
    }
};