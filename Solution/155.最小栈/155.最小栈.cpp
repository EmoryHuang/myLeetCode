/*
 * @Descroption: LeetCode 155. 最小栈
 * @Author: EmoryHuang
 * @Date: 2021-07-04 13:20:05
 * @解题思路:
 * 使用一个最小栈作为辅助，每次往里加最小的元素
 */

class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> st, min_st;
    MinStack() { min_st.push(INT_MAX); }

    void push(int x) {
        st.push(x);
        min_st.push(min(x, min_st.top()));
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min_st.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */