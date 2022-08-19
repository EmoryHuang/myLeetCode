/*
 * @Descroption: 剑指 Offer 64. 求1+2+…+n
 * @Author: EmoryHuang
 * @Date: 2021-07-04 14:08:04
 * @解题思路:
 * 递归并设置终点
 */

class Solution {
   public:
    int sumNums(int n) {
        // 当n不等于零时，左边代码为真，&& 右边代码会执行，则进入递归
        n && (n += sumNums(n - 1));
        return n;
    }
};