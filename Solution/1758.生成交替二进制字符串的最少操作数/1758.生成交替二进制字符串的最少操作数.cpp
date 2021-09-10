/*
 * @Descroption: LeetCode 1758. 生成交替二进制字符串的最少操作数
 * @Author: EmoryHuang
 * @Date: 2021-08-15 12:42:25
 * @Method:
 * 遍历字符串，判断当前字符串和 0101...01 以及 1010...10的差异
 */

class Solution {
   public:
    int minOperations(string s) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == (i % 2 + '0'))
                cnt1++;
            else
                cnt2++;
        }
        return min(cnt1, cnt2);
    }
};