/*
 * @Descroption: LeetCode 232. 用栈实现队列
 * @Author: EmoryHuang
 * @Date: 2021-05-23 15:42:11
 * @解题思路:
 * 通过栈模拟队列
 * 输出时，将输入栈的元素移动到输出栈
 */

class MyQueue {
   public:
    stack<int> s1;  // 输入栈
    stack<int> s2;  // 输出栈
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s1.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */