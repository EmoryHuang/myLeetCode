/*
 * @Descroption: LeetCode 467. 环绕字符串中唯一的子字符串
 * @Author: EmoryHuang
 * @Date: 2022-05-25 09:15:42
 * @Method:
 * 动态规划
 * dp[i] 表示以 i 结尾的子串的最长长度
 * 如果有重叠，只需要考虑最长的一个，因为它覆盖了所有可能的子字符串
 * 具体来说，遍历 p，并维护连续递增的子串长度
 * 如果当前字符与上一个字符在 s 中连续，那么以当前字符结尾的最长长度就从前面累加，否则就是新的开始。
 */


class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if (n < 1) return 0;
        // dp[i] 表示以 i 结尾的子串的最长长度
        // 如果有重叠，只需要考虑最长的一个，因为它覆盖了所有可能的子字符串
        vector<int> dp(26);
        // 维护连续递增的子串长度
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            // 判断是否在循环子串中
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1)
                max_len++;
            else
                max_len = 1;
            dp[p[i] - 'a'] = max(max_len, dp[p[i] - 'a']);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) ans += dp[i];
        return ans;
    }
};