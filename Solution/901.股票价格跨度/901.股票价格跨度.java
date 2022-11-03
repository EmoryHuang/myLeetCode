/*
 * @Descroption: LeetCode 901. 股票价格跨度
 * @Author: EmoryHuang
 * @Date: 2022-10-21 09:14:50
 * @Method:
 * 单调栈
 * 使用单调栈存储天数及其价格，将栈中 <= price 的元素出栈
 * 最终结果为当天时间 - 次大价格时的天数
 */


class StockSpanner {
    Deque<int[]> st;
    int day;

    public StockSpanner() {
        st = new ArrayDeque<>();
        st.push(new int[] { 0, Integer.MAX_VALUE });
        day = 0;
    }

    public int next(int price) {
        day++;
        while (price >= st.peek()[1])
            st.pop();
        int ans = day - st.peek()[0];
        st.push(new int[]{day, price});
        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */