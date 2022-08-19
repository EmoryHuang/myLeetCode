/*
 * @Descroption: LeetCode 160. �ཻ����
 * @Author: EmoryHuang
 * @Date: 2021-03-20 15:32:36
 * @����˼·:
 * �򵥷����������������������ĳ���֮�� n��������ָ��ָ�����������ͷ��㣬
 * �ø��������ָ������ n ����㣬Ȼ������ָ��ͬʱ����ƶ�����һ�������Ľ������ཻ��
 *
 * ����ʹ��һ��������ķ�������һ��ָ��ָ������ A ͷ��㣬��һ��ָ��ָ������ B ͷ��㣬
 * Ȼ��ͬʱ�ƶ���������������βʱָ�뻻����һ������������ָ������ʱ�����ཻ��
 *
 * ����������⣬������ʵҲ�ܼ򵥣� A �� B ���������ȿ��ܲ�ͬ������ A+B �� B+A �ĳ�������ͬ�ģ�
 * ���Ա��� A+B �ͱ��� B+A һ����ͬʱ��������� A,B �ཻ�Ļ� A �� B ��һ������ͬ��
 * ���磺
 *    0, 9, 1, 2, 4, | 3, (2, 4)
 *    3, 2, 4, | 0, 9, 1, (2, 4)
 */

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        if (headA == NULL || headB == NULL) return NULL;
        while (p != q) {
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next;
        }
        return p;
    }
};