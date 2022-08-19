/*
 * @Descroption: LeetCode 1446. 连续字符
 * @Author: EmoryHuang
 * @Date: 2021-04-19 13:15:36
 * @解题思路:
 * 简单题，遍历一遍记录最长连续字符数即可
 */

class Solution {
   public:
    int maxPower(string s) {
        int len = s.size();
        if (len == 1) return 1;
        int ans = 0, tmp = 0;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1])
                tmp++;
            else
                tmp = 0;
            ans = max(ans, tmp + 1);
        }
        return ans;
    }
};