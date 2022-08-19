/*
 * @Descroption: 剑指 Offer 58 - II. 左旋转字符串
 * @Author: EmoryHuang
 * @Date: 2021-07-07 19:43:36
 * @解题思路:
 * 简单题, 切片或遍历拼接
 */

class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        string ans;
        int len = s.size();
        for (int i = n; i < n + len; i++) ans += s[i % len];
        return ans;
    }
};