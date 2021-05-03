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