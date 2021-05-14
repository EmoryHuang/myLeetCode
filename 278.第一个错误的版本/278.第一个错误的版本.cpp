/*
 * @Descroption: LeetCode 278. 第一个错误的版本
 * @Author: EmoryHuang
 * @Date: 2021-05-10 17:54:36
 * @解题思路:
 * 二分法寻找左端点
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};