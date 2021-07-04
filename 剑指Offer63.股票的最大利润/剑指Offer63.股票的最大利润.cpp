/*
 * @Descroption: 剑指 Offer 63. 股票的最大利润
 * @Author: EmoryHuang
 * @Date: 2021-07-04 13:58:45
 * @解题思路:
 * 因为买入价一定在卖出价之前，因此维护一个最小值，遍历价格寻找最大利润
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int ans = 0, min = INT_MAX;
        for (int price : prices) {
            if (price < min)
                min = price;
            else
                ans = max(ans, price - min);
        }
        return ans;
    }
};