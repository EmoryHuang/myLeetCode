/*
 * @Descroption: LeetCode 639. 解码方法 II
 * @Author: EmoryHuang
 * @Date: 2021-09-27 19:33:15
 * @Method:
 * 动态规划
 * dp[i]表示前i个字符的解码方案数
 * dp[i] = α * dp[i-1] + β * dp[i-2]
 * 分别考虑一位数和两位数的解码方案
 * 解码单个字符，分成 0、1~9、* 来分别讨论
 * 解码两个字符，分成 **、*X、X*、XX 来分别讨论
 */

class Solution {
   public:
    int decode1(char c) {
        // 解码单个字符
        if (c == '0') return 0;
        if (c == '*') return 9;  // [1 - 9]
        return 1;
    }
    int decode2(char c1, char c2) {
        if (c1 == '*' && c2 == '*') return 15;  // [11 - 19] and [21 - 26]
        if (c1 == '*') return c2 <= '6' ? 2 : 1;
        if (c2 == '*') {
            if (c1 == '1') return 9;  // c2 == 1 - 9
            return c1 == '2' ? 6 : 0;
        }
        int sum = (c1 - '0') * 10 + (c2 - '0');
        if (sum >= 10 && sum <= 26) return 1;
        return 0;
    }
    int numDecodings(string s) {
        // dp[i]表示前i个字符的解码方案数
        // a = f[i-2], b = f[i-1], c = f[i]
        long long a = 0, b = 1, c = 0;
        int mod = 1000000007;
        for (int i = 1; i <= s.length(); i++) {
            // 考虑一位数的解码方案
            c = decode1(s[i - 1]) * b % mod;
            // 考虑两位数的解码方案
            if (i > 1) c += decode2(s[i - 2], s[i - 1]) * a;
            c %= mod;
            a = b;
            b = c;
        }
        return c;
    }
};