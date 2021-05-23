/*
 * @Descroption: LeetCode 225. 用队列实现栈
 * @Author: EmoryHuang
 * @Date: 2021-05-23 15:29:11
 * @解题思路:
 * 通过队列模拟栈
 * 可以用两个队列或者一个队列实现
 */

class MyStack {
   public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */