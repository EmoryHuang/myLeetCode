/*
 * @Descroption: LeetCode 237. ɾ�������еĽڵ�
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:32:36
 * @����˼·:
 * ������Ŀ�ܼ򵥣�Ȼ��ʼд���üһ� `head` ȥ���ˣ����˷����ۣ��ðɸ�ǣ�ûʲô��˵��
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
