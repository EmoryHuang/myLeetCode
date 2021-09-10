/*
 * @Descroption: LeetCode 403. 青蛙过河
 * @Author: EmoryHuang
 * @Date: 2021-04-29 16:32:36
 * @解题思路:
 * 对于第`i`个石头，前面的石头`j`能否跳到该石头,假设两石头间的距离为`diff = stones[i]-stones[j]`
 * 需要判断 `j` 是否存在可以跳跃 `diff` 步 的能力，而这个能力是由 石头 `j` 前面的石头决定的
 * 当前面能够跳 `diff` 步石头 `i` 时，那么石头 `i` 可跳的步数增加 `diff - 1 || diff || diff + 1`
 * 因此，`dp[i][j]` 表示 第 `i` 个石头是否可以跳 `j` 步
 */

class Solution {
   public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len + 1));
        dp[0][1] = true;  // 第0个石头可以跳1步
        for (int i = 1; i < len; i++) {
            bool flag = false;
            for (int j = i - 1; j >= 0; j--) {  // 从后向前枚举
                int diff = stones[i] - stones[j];
                if (diff > i) break;        // 间距过大无法达到
                if (dp[j][diff] == true) {  // 如果第j个石头能跳diff步
                    // 那么说明第j个石头能跳到i，则第i块石头允许的步数
                    dp[i][diff - 1] = true;
                    dp[i][diff] = true;
                    dp[i][diff + 1] = true;
                    flag = true;
                }
            }
            // 跳不到终点
            if (i == len - 1 && !flag) return false;
        }
        return true;
    }
};