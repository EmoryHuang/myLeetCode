/*
 * @Description: LeetCode 121. 买卖股票的最佳时机
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:27:20
 * @解题思路:
 * 贪心，维护最小值
 */

import java.util.*;

class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, min = 0x3f3f3f3f;
        for (int price : prices) {
            min = Math.min(min, price);
            ans = Math.max(ans, price - min);
        }
        return ans;
    }
}