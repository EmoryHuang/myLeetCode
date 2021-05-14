/*
 * @Descroption: LeetCode 367. 有效的完全平方数
 * @Author: EmoryHuang
 * @Date: 2021-04-23 14:49:36
 * @解题思路: 平方数判断，在不使用 sqrt 的情况下，可以使用二分查找，或者可以使用牛顿迭代法
 */

class Solution {
   public:
    // 方法一：二分查找
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        long left = 2, right = num / 2;
        while (left <= right) {
            long x = left + (right - left) / 2;
            if (x * x == num)
                return true;
            else if (x * x > num)
                right = x - 1;
            else
                left = x + 1;
        }
        return false;
    }

    // 方法二：牛顿迭代法
    // bool isPerfectSquare(int num) {
    //     if (num < 2) return true;
    //     long x = num / 2;
    //     while (x * x > num) x = (x + num / x) / 2;
    //     return (x * x == num);
    // }
};