/*
 * @Descroption: LeetCode 1475. 商品折扣后的最终价格
 * @Author: EmoryHuang
 * @Date: 2022-09-01 09:06:04
 * @Method:
 * 单调栈
 * 从后往前遍历，维护最小值
 */


class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] ans = new int[n];
        Deque<Integer> st = new ArrayDeque<Integer>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() > prices[i])
                st.pop();
            ans[i] = st.isEmpty() ? prices[i] : prices[i] - st.peek();
            st.push(prices[i]);
        }
        return ans;
    }
}