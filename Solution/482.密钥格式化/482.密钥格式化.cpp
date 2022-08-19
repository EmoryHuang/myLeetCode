/*
 * @Descroption: LeetCode 482. 密钥格式化
 * @Author: EmoryHuang
 * @Date: 2021-04-24 15:26:36
 * @解题思路:
 * 遍历字符串，查找所有非 '-' 字符并加入，之后再次遍历从后向前每隔 k 的字符插入 '-'
 */

class Solution {
   public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        for (int i = 0; i < s.size(); i++)  // 查找所有非 '-' 字符并加入
            if (s[i] != '-') ans += toupper(s[i]);
        for (int i = ans.size() - k; i > 0; i -= k) {  // 从后向前插入 '-'
            ans.insert(i, "-");
        }
        return ans;
    }
};