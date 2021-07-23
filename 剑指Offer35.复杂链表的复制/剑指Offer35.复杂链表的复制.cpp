/*
 * @Descroption: ��ָ Offer 35. ��������ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-07-23 19:20:53
 * @����˼·:
 * ���� + ��ϣ��
 * ʹ�ù�ϣ��洢���ֹ��Ľڵ�
 * �����ǰ�ڵ��Ѿ�������������ô��ֱ�ӷ���
 * �����ǰ�ڵ�� next �� random ��û�б��������͵ݹ�ؽ��д���
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    map<Node*, Node*> ans;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (ans.count(head) != 0) return ans[head];
        Node* copy = new Node(head->val);
        ans[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};