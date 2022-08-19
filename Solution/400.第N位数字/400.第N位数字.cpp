/*
 * @Descroption: LeetCode 400. 第 N 位数字
 * @Author: EmoryHuang
 * @Date: 2021-11-30 09:13:03
 * @Method:
 * 模拟
 * 长度为 l 的数字有 [10^(l - 1), 10^l - 1)] ，共 9 * 10^(l - 1) 个
 * 首先判断第 n 位所在数字的长度，然后求出第 n 位所在数字的值
 * 第 n 个数字是 10^(l - 1) + (n_l - 1) / l
 * 位数为 (n - 1) % l
 * */

class Solution {
   public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        long long l = 1, base = 9;
        while (n > base * l) {
            n -= base * l;
            l++;
            base *= 10;
        }
        int num = pow(10, l - 1) + (n - 1) / l;
        int pos = (n - 1) % l;
        return to_string(num)[pos] - '0';
    }
};