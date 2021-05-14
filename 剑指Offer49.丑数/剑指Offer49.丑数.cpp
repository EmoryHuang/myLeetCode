/*
 * @Descroption: LeetCode 263. 丑数
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:54:36
 * @解题思路:
 * 题目很简单，不断对 2，3，5 整除即可
 */

class Solution {
   public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};