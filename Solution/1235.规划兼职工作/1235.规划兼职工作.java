/*
 * @Descroption: LeetCode 1235. 规划兼职工作
 * @Author: EmoryHuang
 * @Date: 2022-10-22 09:54:35
 * @Method:
 * 动态规划
 * 按结束时间从小到大进行排序，dp[i] 表示前 i 份工作的最大利润
 * 状态转移方程 dp[i] = max(dp[i - 1], dp[k] + profit[i - 1])
 * 其中 k 表示满足结束时间小于等于第 i−1 份工作开始时间的兼职工作数量
 */


class Solution {
    int binarysearch(int[][] jobs, int right, int target) {
        int left = 0;
        while (left < right) {
            int mid = left + right >> 1;
            if (jobs[mid][1] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        // dp[i] 表示前 i 份工作的最大利润
        int[] dp = new int[n + 1];
        int[][] jobs = new int[n][];
        for (int i = 0; i < n; i++) {
            jobs[i] = new int[] { startTime[i], endTime[i], profit[i] };
        }
        // 按结束时间从小到大进行排序
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        for (int i = 1; i <= n; i++) {
            // 状态转移方程 dp[i] = max(dp[i - 1], dp[k] + profit[i - 1])
            // 其中 k 表示满足结束时间小于等于第 i−1 份工作开始时间的兼职工作数量
            int k = binarysearch(jobs, i - 1, jobs[i - 1][0]);
            dp[i] = Math.max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
}