/*
 * @Descroption: 剑指 Offer 30. 包含min函数的栈
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:57:35
 * @Method:
 * 使用一个最小栈作为辅助，每次往里加最小的元素
 */

import java.util.*;

class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> st, st_min;

    public MinStack() {
        st = new Stack<>();
        st_min = new Stack<>();
        st_min.add(Integer.MAX_VALUE);
    }

    public void push(int x) {
        st.add(x);
        st_min.add(Math.min(st_min.peek(), x));
    }

    public void pop() {
        st.pop();
        st_min.pop();
    }

    public int top() {
        return st.peek();
    }

    public int min() {
        return st_min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */