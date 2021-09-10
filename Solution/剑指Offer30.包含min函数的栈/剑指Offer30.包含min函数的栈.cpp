/*
 * @Descroption: ��ָ Offer 30. ����min������ջ
 * @Author: EmoryHuang
 * @Date: 2021-07-04 13:18:43
 * @����˼·:
 * ʹ��һ����Сջ��Ϊ������ÿ���������С��Ԫ��
 */

class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> st, min_st;
    MinStack() { min_st.push(INT_MAX); }

    void push(int x) {
        st.push(x);
        min_st.push(::min(x, min_st.top()));
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() { return st.top(); }

    int min() { return min_st.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */