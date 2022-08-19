/*
 * @Descroption: LeetCode 725. �ָ�����
 * @Author: EmoryHuang
 * @Date: 2021-09-22 16:01:38
 * @Method:
 * ���ȱ���������¼������
 * ���ÿ��ƽ����������Ҫ������ӵ�����������
 * ֮���ٴα����������������Ԫ�ؼ��ɣ�����ע���������ʽ
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        int n = 0;
        while (p) {
            p = p->next;
            n++;
        }
        // ÿ��ƽ����������Ҫ������ӵ�����������
        int avg = n / k, add = n % k;
        vector<ListNode*> ans(k, nullptr);
        p = head;
        for (int i = 0; i < k; i++) {
            if (!p) break;
            int len = avg + (i < add ? 1 : 0);
            ans[i] = p;
            for (int j = 0; j < len - 1; j++) p = p->next;
            ListNode* nxt = p->next;
            p->next = nullptr;
            p = nxt;
        }
        return ans;
    }
};