/*
 * @Descroption: 剑指 Offer 09. 用两个栈实现队列
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:49:35
 * @Method:
 * 分别维护入栈和出栈
 * 进入元素时，将元素放入 s_in
 * 删除元素时，
 *     若 s_out 非空，则弹出s_out，
 *     若 s_out 为空，则把 s_in 中的东西全部放入 s_out 中，弹出s_out，
 *     若 s_out, s_in 都为空，返回 -1
 */

import java.util.*;

class CQueue {
    Stack<Integer> stIn;
    Stack<Integer> stOut;

    public CQueue() {
        stIn = new Stack<>();
        stOut = new Stack<>();
    }

    public void appendTail(int value) {
        stIn.add(value);
    }

    public int deleteHead() {
        if (stOut.isEmpty()) {
            if (stIn.isEmpty()) {
                return -1;
            }
            while (!stIn.isEmpty()) {
                stOut.add(stIn.pop());
            }
        }
        return stOut.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */