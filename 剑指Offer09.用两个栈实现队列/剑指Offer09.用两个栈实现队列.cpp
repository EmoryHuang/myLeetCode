/*
 * @Descroption: 剑指 Offer 09. 用两个栈实现队列
 * @Author: EmoryHuang
 * @Date: 2021-06-29 19:57:00
 * @解题思路:
 * 使用两个栈，一个栈入，一个栈出
 * 进入元素时，将元素放入 s_in
 * 删除元素时，
 *     若 s_out 非空，则弹出s_out，
 *     若 s_out 为空，则把 s_in 中的东西全部放入 s_out 中，弹出s_out，
 *     若 s_out, s_in 都为空，返回 -1
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
        if (s_out.empty()) {  // 若 s_out 为空
            if (s_in.empty()) return -1;
            // 把 s_in 中的东西全部放入 s_out 中
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