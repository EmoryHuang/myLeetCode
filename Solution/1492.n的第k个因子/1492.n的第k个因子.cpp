/*
 * @Descroption: LeetCode 1492. n 的第 k 个因子
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:53:36
 * @解题思路:
 * 简单题，找所有因子，返回第 k 个即可
 */

class Solution {
   public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) k--;
            if (k == 0) return i;
        }
        return -1;
    }
};