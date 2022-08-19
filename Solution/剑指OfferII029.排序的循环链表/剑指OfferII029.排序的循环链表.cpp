/*
 * @Descroption: ��ָ Offer II 029. �����ѭ������
 * @Author: EmoryHuang
 * @Date: 2022-06-18 09:09:30
 * @Method:
 * ����ѭ���б��Ƚ�Ԫ�ص�ֵ�����뵽���ʵ�λ�ã���Ҫע��߽�������
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        // �� head Ϊ�գ���ֱ�Ӳ���
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        // ��ֻ��һ���ڵ㣬��ֱ�Ӳ���
        if (head->next == head) {
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        // Ѱ�Ҳ���λ��
        Node* cur = head;
        while (cur->next != head) {
            if (cur->val <= insertVal && insertVal <= cur->next->val) break;
            if (cur->val > cur->next->val)
                if (insertVal > cur->val || insertVal < cur->next->val) break;
            cur = cur->next;
        }
        // ����
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};