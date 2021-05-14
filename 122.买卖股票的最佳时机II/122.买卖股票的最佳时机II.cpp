/*
 * @Descroption: LeetCode 122. 买卖股票的最佳时机 II
 * @Author: EmoryHuang
 * @Date: 2021-03-25 09:30:36
 * @解题思路:
 * 其实题目的意思可以进行简化，只要今天的价格比昨天的高就可以卖出，结果与不能同时交易是一样的
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};