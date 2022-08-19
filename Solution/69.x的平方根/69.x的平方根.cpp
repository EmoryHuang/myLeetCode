/*
 * @Descroption: LeetCode 69. x 的平方根
 * @Author: EmoryHuang
 * @Date: 2021-03-27 10:49:36
 * @解题思路: 可以采用牛顿迭代法和二分搜索法
 * 简要说一下二分查找，x 平方根的整数部分 ans 是满足 k^2 ≤ x 的最大 k 值，
 * 因此可以对 k 进行二分查找，从而得到答案，
 * 在二分查找的每一步中，我们只需要比较中间元素mid的平方与x的大小关系，并通过比较的结果调整上下界的范围
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (mid <= x / mid)  //除法防止溢出
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};