/*
 * @Descroption: ��ָ Offer II 023. ��������ĵ�һ���غϽڵ�
 * @Author: EmoryHuang
 * @Date: 2021-08-03 20:31:44
 * @Method:
 * ��һ��ָ��ָ������ A ͷ��㣬��һ��ָ��ָ������ B ͷ��㣬
 * Ȼ��ͬʱ�ƶ���������������βʱָ�뻻����һ������������ָ������ʱ�����ཻ��
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha = headA, *hb = headB;
        if (!ha || !hb) return nullptr;
        while (ha != hb) {
            ha = ha ? ha->next : headB;
            hb = hb ? hb->next : headA;
        }
        return ha;
    }
};