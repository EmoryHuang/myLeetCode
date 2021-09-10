/*
 * @Descroption: LeetCode 483. 最小好进制
 * @Author: EmoryHuang
 * @Date: 2021-06-18 17:20:00
 * @解题思路:
 * 设 n 的 k 进制长度为 len，那么有 (n)10 = (11..1)k = k^0 + k^1 + ... + k^(len-1)
 * len = 1 时, k^0 = 1, n = 1, 与题意不符;
 * len = 2 时, k^0 + k^1 = n, k = n - 1 ≥ 2
 * 因此 len ≥ 2
 * 令 s = len - 1
 * 依据二项式定理进行放缩，可以得到：k^s < n < (k+1)^s
 * 即 k < n^(1/s) < k+1
 * 我们只需要验证 n^(1/s) 是否为正整数即可。
 */

class Solution {
   public:
    // 数学方法
    string smallestGoodBase(string n) {
        long num = stol(n);
        int max = (int)(log(num) / log(2) + 1);
        for (int len = max; len > 2; len--) {
            // k < n^(1/s) < k+1
            long k = powl(num, 1.0 / (len - 1));
            long ans = 0;
            // 检查 len 个 1 是否为 n
            for (int i = 0; i < len; i++) ans = ans * k + 1;
            if (ans == num) return to_string(k);
        }
        return to_string(num - 1);
    }
};