/*
 * @Descroption: LeetCode 1052. 爱生气的书店老板
 * @Author: EmoryHuang
 * @Date: 2021-08-06 16:10:53
 * @Method:
 * 滑动窗口
 * 首先排除掉不生气时的顾客，只考虑生气时的顾客
 * 建立大小为 minutes 的滑动窗口，计算不生气时的最大顾客数目
 */

class Solution {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, n = customers.size();
        // 计算不生气时的顾客人数
        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0) {
                ans += customers[i];
                customers[i] = 0;
            }
        // 滑动窗口
        int r = minutes, sumn = 0;
        for (int i = 0; i < r; i++) sumn += customers[i];
        int maxn = sumn;
        while (r < n) {
            sumn += customers[r];
            sumn -= customers[r - minutes];
            maxn = max(maxn, sumn);
            r++;
        }
        return ans + maxn;
    }
};