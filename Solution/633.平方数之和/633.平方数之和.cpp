/*
 * @Descroption: LeetCode 633. 平方数之和
 * @Author: EmoryHuang
 * @Date: 2021-04-28 13:44:36
 * @解题思路:
 * 设置双指针，判断`a * a + b * b`的值并向中间移动
 */

class Solution {
   public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c);
        while (a <= b) {
            if (a * a + b * b == c)
                return true;
            else if (a * a + b * b > c)
                b--;
            else
                a++;
        }
        return false;
    }
};