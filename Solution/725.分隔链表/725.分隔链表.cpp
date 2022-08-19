/*
 * @Descroption: LeetCode 725. 分隔链表
 * @Author: EmoryHuang
 * @Date: 2021-09-22 16:01:38
 * @Method:
 * 首先遍历链表，记录链表长度
 * 获得每组平均数量，需要额外添加的数量的组数
 * 之后再次遍历链表，按规则填充元素即可，另外注意输出的形式
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
        // 每组平均数量，需要额外添加的数量的组数
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