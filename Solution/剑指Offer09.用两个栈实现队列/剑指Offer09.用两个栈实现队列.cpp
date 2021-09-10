/*
 * @Descroption: ��ָ Offer 09. ������ջʵ�ֶ���
 * @Author: EmoryHuang
 * @Date: 2021-06-29 19:57:00
 * @����˼·:
 * ʹ������ջ��һ��ջ�룬һ��ջ��
 * ����Ԫ��ʱ����Ԫ�ط��� s_in
 * ɾ��Ԫ��ʱ��
 *     �� s_out �ǿգ��򵯳�s_out��
 *     �� s_out Ϊ�գ���� s_in �еĶ���ȫ������ s_out �У�����s_out��
 *     �� s_out, s_in ��Ϊ�գ����� -1
 */

class CQueue {
   public:
    stack<int> s_in;
    stack<int> s_out;
    CQueue() {}

    void appendTail(int value) { 
        s_in.push(value); 
    }

    int deleteHead() {
        if (s_out.empty()) {  // �� s_out Ϊ��
            if (s_in.empty()) return -1;
            // �� s_in �еĶ���ȫ������ s_out ��
            while (!s_in.empty()) s_out.push(s_in.top()), s_in.pop();
        }
        int ans = s_out.top();
        s_out.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */