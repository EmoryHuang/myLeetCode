/*
 * @Descroption: LeetCode 907. 子数组的最小值之和
 * @Author: EmoryHuang
 * @Date: 2022-10-28 09:36:20
 * @Method:
 * 动态规划
 * dp[i] 表示以 i 为结尾的子数组最小值之和
 * 维护一个单调栈，求出元素 x 的左边第一个比它小的元素
 * 即求出以 x 为最右且最小的子序列的最大长度 k
 * 状态转移方程：dp[i] = dp[i - k] + k * arr[i]
 */

class Solution {
    public int sumSubarrayMins(int[] arr) {
        int MOD = 1000000007;
        int n = arr.length, ans = 0;
        // dp[i] 表示以 i 为结尾的子数组最小值之和
        int[] dp = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        // 维护一个单调栈，求出元素 x 的左边第一个比它小的元素
        // 即求出以 x 为最右且最小的子序列的最大长度 k
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peekLast()] > arr[i]) {
                st.pollLast();
            }
            int k = st.isEmpty() ? i + 1 : i - st.peekLast();
            dp[i] = k * arr[i] + (st.isEmpty() ? 0 : dp[i - k]);
            ans = (ans + dp[i]) % MOD;
            st.add(i);
        }
        return ans;
    }
}