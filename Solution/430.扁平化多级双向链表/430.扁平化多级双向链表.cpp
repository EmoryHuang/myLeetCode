/*
 * @Descroption: LeetCode 430. ��ƽ���༶˫������
 * @Author: EmoryHuang
 * @Date: 2021-09-24 11:06:23
 * @Method:
 * dfs
 * ������Ҫ�� child ָ���������� node �� node.next ֮��
 * �� child �ǿգ������ȴ������½������������
 * node �� child ������node.next �� child_last ����
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    Node* dfs(Node* node) {
        // ��¼��������һ���ڵ�
        Node *cur = node, *last;
        while (cur) {
            Node* nxt = cur->next;  // ��¼ next
            // ��������ӽڵ㣬��ô�ȴ����ӽڵ�
            if (cur->child) {
                Node* child_last = dfs(cur->child);
                // ��ƽ������ cur �� child ����
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                // ��� next �ǿգ��ͽ���������������һ���ڵ�����
                if (nxt) {
                    child_last->next = nxt;
                    nxt->prev = child_last;
                }
                last = child_last;
            } else
                last = cur;
            cur = nxt;
        }
        return last;
    }
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};