/*
 * @Descroption: LeetCode 142. �������� II
 * @Author: EmoryHuang
 * @Date: 2021-05-13 15:25:36
 * @����˼·:
 * ���ȴ�������ָ�룬�ж������Ƿ���ڻ�
 * Ȼ���ҵ��뻷��㣬
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        // �ж��Ƿ��л�
        bool flag = false;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                flag = true;
                break;
            }
        }
        if (flag) {
            p = head;
            while (p != q) {
                p = p->next;
                q = q->next;
            }
            return p;
        }
        return nullptr;
    }
};