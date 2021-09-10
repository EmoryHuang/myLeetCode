/*
 * @Descroption: LeetCode 2. �������
 * @Author: EmoryHuang
 * @Date: 2021-03-15 19:30:36
 * @����˼·: ��Ϊ�����ǵ���ģ����Կ���ֱ�ӽ��а��ַ����Ӽ��ķ������м���
 *          �����ǰ����������Ӧλ�õ�����Ϊ n1,n2����λֵΪ carry�������ǵĺ�Ϊ n1+n2+carry
 *          ��������Ӧλ�õ�����Ϊ (n1+n2+carry) % 10�����µĽ�λֵΪ (n1+n2+carry) / 10
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
            carry = num / 10;  //��λ
            num = num % 10;    //��һ������
            if (!head)         //��ʼΪ��
                head = tail = new ListNode(num);
            else {
                tail->next = new ListNode(num);
                tail = tail->next;  //����β���
            }
            if (l1) l1 = l1->next;  //��l1����ֵ
            if (l2) l2 = l2->next;  //��l2����ֵ
            if (carry > 0) tail->next = new ListNode(carry);
        }
        return head;
    }
};