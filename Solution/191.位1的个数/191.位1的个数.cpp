/*
 * @Descroption: LeetCode 191. 位 1 的个数
 * @Author: EmoryHuang
 * @Date: 2021-03-21 14:13:36
 * @解题思路:
 * 方法一：整除取余，`n % 2`
 *
 * 方法二：直接判断最低位的数是不是 1，通过与运算即可 `n & 1`
 */

class Solution {
   public:
    // 方法一：整除取余
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n % 2;
            n >>= 1;
        }
        return ans;
    }

    // 方法二：直接判断最低位的数是不是1
    // int hammingWeight(uint32_t n) {
    //     int ans = 0;
    //     while (n) {
    //         ans += n & 1;
    //         n >>= 1;
    //     }
    //     return ans;
    // }
};