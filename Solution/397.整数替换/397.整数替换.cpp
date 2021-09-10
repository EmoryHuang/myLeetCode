/*
 * @Descroption: LeetCode 397. 整数替换
 * @Author: EmoryHuang
 * @Date: 2021-05-07 20:12:36
 * @解题思路:
 * 简单题，直接用递归解决即可
 */

class Solution {
   public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;  // 防溢出
        if (n % 2 == 0)
            return 1 + integerReplacement(n / 2);
        else
            return 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
    }
};