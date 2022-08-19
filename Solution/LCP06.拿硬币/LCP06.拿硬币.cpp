/*
 * @Descroption: LCP 06. 拿硬币
 * @Author: EmoryHuang
 * @Date: 2021-07-08 18:50:15
 * @解题思路:
 * 简单题，除以2向上取整
 */

class Solution {
   public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (double coin : coins) ans += ceil(coin / 2);
        return ans;
    }
};