/*
 * @Descroption: LeetCode 1716. 计算力扣银行的钱
 * @Author: EmoryHuang
 * @Date: 2021-05-06 18:40:36
 * @解题思路:
 * 简单题，等差数列求和
 */

class Solution {
   public:
    int totalMoney(int n) {
        return n / 7 * 28 + (n / 7) * (n / 7 - 1) / 2 * 7 +
               (n / 7 + 1 + n / 7 + n % 7) * (n % 7) / 2;
    }
};