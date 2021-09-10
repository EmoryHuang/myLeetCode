/*
 * @Descroption: LeetCode 441. 排列硬币
 * @Author: EmoryHuang
 * @Date: 2021-07-22 20:00:05
 * @解题思路:
 * 方法一：二分
 * 二分法寻找右端点
 * 方法二：解方程
 * x(x+1)/2=n
 */

class Solution {
   public:
    // 方法一：二分
    // int arrangeCoins(int n) {
    //     int l = 1, r = n / 2 + 1;
    //     while (l < r) {
    //         int mid = l + (r - l + 1) / 2;
    //         if (mid * (mid + 1) <= 2 * n)
    //             l = mid;
    //         else
    //             r = mid - 1;
    //     }
    //     return l;
    // }

    // 方法二：解方程
    int arrangeCoins(int n) { 
        return (int)(-1 + sqrt(1 + 8 * (long)n)) / 2; 
    }
};