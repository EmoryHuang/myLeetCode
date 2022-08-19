/*
 * @Descroption: LeetCode 372. 超级次方
 * @Author: EmoryHuang
 * @Date: 2021-04-23 15:10:36
 * @解题思路:
 * 首先对数组 b 进行处理，然后应用快速幂的方法求值
 */

class Solution {
   public:
    int mod = 1337;
    // 快速幂
    int quickPow(int a, int b) {
        int ans = 1;
        while (b > 0) {
            if (b % 2) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int len = b.size();
        int ans = 1;
        a %= mod;
        for (int i = len - 1; i >= 0; i--) {
            ans = ans * quickPow(a, b[i]) % mod;
            a = quickPow(a, 10);
        }
        return ans;
    }
};