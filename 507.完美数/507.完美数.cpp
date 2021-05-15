/*
 * @Descroption: LeetCode 507. 完美数
 * @Author: EmoryHuang
 * @Date: 2021-03-25 14:05:36
 * @解题思路: 简单枚举
 */

class Solution {
   public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) sum += i;
        }
        return sum == num;
    }
};