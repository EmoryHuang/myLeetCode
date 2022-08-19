/*
 * @Descroption: LeetCode 1024. 视频拼接
 * @Author: EmoryHuang
 * @Date: 2021-10-20 20:34:25
 * @Method:
 * 方法一：动态规划
 * dp[i] 表示将区间 [0, i) 覆盖需要的最小区间
 * 状态转移方程：dp[i] = min(dp[i], dp[l] + 1)
 *
 * 方法二：贪心
 * 使用 maxr[i] 表示左端点 i 处能够到达的最右位置
 * 贪心遍历每个位置，到达当前位置能够达到的最远位置
 */

class Solution {
   public:
    // 方法一：动态规划
    // int videoStitching(vector<vector<int>>& clips, int time) {
    //     // dp[i] 表示将区间 [0, i) 覆盖需要的最小区间
    //     vector<int> dp(time + 1, 0x3f3f3f3f);
    //     dp[0] = 0;
    //     for (int i = 1; i <= time; i++) {
    //         for (auto clip : clips) {
    //             int l = clip[0], r = clip[1];
    //             if (i > l && i <= r) dp[i] = min(dp[i], dp[l] + 1);
    //         }
    //     }
    //     return dp[time] == 0x3f3f3f3f ? -1 : dp[time];
    // }

    // 方法二：贪心
    int videoStitching(vector<vector<int>>& clips, int time) {
        // maxr[i] 表示左端点 i 处能够到达的最右位置
        vector<int> maxr(time, 0);
        int ans = 0, last = 0, pre = 0;
        for (auto clip : clips) {
            int l = clip[0], r = clip[1];
            if (l < time) maxr[l] = max(maxr[l], r);
        }
        // 遍历每个位置
        for (int i = 0; i < time; i++) {
            last = max(last, maxr[i]);
            if (i == last) return -1;  // 下一个位置无法被覆盖
            if (i == pre) {
                // 到达了上一个位置
                pre = last;
                ans++;
            }
        }
        return ans;
    }
};