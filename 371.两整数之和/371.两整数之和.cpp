/*
 * @Descroption: LeetCode 371. 两整数之和
 * @Author: EmoryHuang
 * @Date: 2021-06-11 17:22:00
 * @解题思路:
 * 两个整数a, b
 * a ^ b是无进位的相加
 * a & b得到每一位的进位
 * 让无进位相加的结果与进位不断的异或， 直到进位为0
 */

class Solution {
   public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (unsigned int)(a & b) << 1;
        if (carry) return getSum(sum, carry);
        return sum;
    }
};