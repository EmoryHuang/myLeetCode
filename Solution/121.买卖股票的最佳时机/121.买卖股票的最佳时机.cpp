/*
 * @Descroption: LeetCode 121. 买卖股票的最佳时机
 * @Author: EmoryHuang
 * @Date: 2021-03-25 10:45:36
 * @解题思路: 简单的动态规划问题
 * 第 i 天可以获得的最大利润 =
 * MAX （第 i-1 天可以获得的最大利润，第 i 天的价格 - 前 i-1 天中的最小价格）
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minp = prices[0], maxp = 0;
        for (int i = 1; i < len; i++) {
            maxp = max(maxp, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};