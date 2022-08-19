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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        else if(l2==nullptr){
            return l1;
        }
        else if(l1->val > l2->val){
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        else{
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
    }
};