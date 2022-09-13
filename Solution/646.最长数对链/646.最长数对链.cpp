/*
 * @Descroption: LeetCode 646. 最长数对链
 * @Author: EmoryHuang
 * @Date: 2021-06-14 13:36:00
 * @解题思路:
 * 方法一：贪心思想，
 * 以数对的第二个值从小到大排序
 * 然后比较 pairs[i][0] 和 pre 的大小
 *
 * 方法二：动态规划
 * dp[i]表示以 pairs[i] 结尾的最长链的长度
 * 状态转移方程：dp[i] = max(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    // 方法一：贪心
    // static bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end(), cmp);
    //     int ans = 1, pre = pairs[0][1];
    //     for (int i = 1; i < pairs.size(); i++) {
    //         if (pairs[i][0] > pre) {
    //             ans++;
    //             pre = pairs[i][1];
    //         }
    //     }
    //     return ans;
    // }

    // 方法二：动态规划
    static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        // dp[i]表示以 pairs[i] 结尾的最长链的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};