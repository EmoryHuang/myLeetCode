/*
 * @Descroption: LeetCode 2336. 无限集中的最小数字
 * @Author: EmoryHuang
 * @Date: 2023-07-20 09:51:30
 * @Method:
 * 维护无限集中的最小值
 * 小根堆记录插入的值
 */

import java.util.*;

class SmallestInfiniteSet {
    PriorityQueue<Integer> st;
    int min;

    public SmallestInfiniteSet() {
        st = new PriorityQueue<>();
        min = 1;
    }

    public int popSmallest() {
        if (!st.isEmpty()) {
            return st.poll();
        }
        return min++;
    }

    public void addBack(int num) {
        if (num < min && !st.contains(num)) {
            st.offer(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */