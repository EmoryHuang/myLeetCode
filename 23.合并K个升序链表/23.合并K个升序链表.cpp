/*
 * @Descroption: LeetCode 23. 合并K个升序链表
 * @Author: EmoryHuang
 * @Date: 2021-05-27 21:05:17
 * @解题思路:
 * 方法一：顺序合并
 * 在合并两个升序链表的基础上，遍历k个链表，依次合并
 *
 * 方法二：分治
 * 用分治的方法进行合并
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
    // 合并两个升序链表
    ListNode* mergeTwoList(ListNode* lista, ListNode* listb) {
        if (!lista) return listb;
        if (!listb) return lista;
        if (lista->val > listb->val) {
            listb->next = mergeTwoList(lista, listb->next);
            return listb;
        } else {
            lista->next = mergeTwoList(lista->next, listb);
            return lista;
        }
    }
    // 方法一：顺序合并
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode* ans = nullptr;
    //     for (int i = 0; i < lists.size(); i++) ans = mergeTwoList(ans, lists[i]);
    //     return ans;
    // }

    // 方法二：分治
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + (r - l) / 2;
        ListNode* l1 = merge(lists, l, mid);
        ListNode* l2 = merge(lists, mid + 1, r);
        return mergeTwoList(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};