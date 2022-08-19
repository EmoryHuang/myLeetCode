/*
 * @Descroption: LeetCode 258. 各位相加
 * @Author: EmoryHuang
 * @Date: 2021-05-22 15:10:00
 * @解题思路:
 * 简单题，如果num小于10则返回
 * 否则计算各个位上的数字之和
 */

class Solution {
   public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};