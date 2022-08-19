/*
 * @Descroption: LeetCode 67. 二进制求和
 * @Author: EmoryHuang
 * @Date: 2021-05-10 10:53:36
 * @解题思路: 模拟二进制加法，维护 carry，表示进位
 */

class Solution {
   public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1;
        if (m + 1 == 0) return b;
        if (n + 1 == 0) return a;
        int carry = 0;
        string ans;
        while (m >= 0 || n >= 0) {
            if (m >= 0) carry += a[m--] - '0';
            if (n >= 0) carry += b[n--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        if (carry) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};