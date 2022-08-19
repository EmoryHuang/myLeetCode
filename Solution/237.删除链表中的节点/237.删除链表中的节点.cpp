/*
 * @Descroption: LeetCode 237. 删除链表中的节点
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:32:36
 * @解题思路:
 * 看完题目很简单，然后开始写，好家伙 `head` 去哪了，翻了翻评论，好吧告辞，没什么好说的
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
