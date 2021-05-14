/*
 * @Descroption: LeetCode 434. 字符串中的单词数
 * @Author: EmoryHuang
 * @Date: 2021-03-26 15:46:36
 * @解题思路:
 * 基础题，在末尾添加一个空格，可以将空串，空格结尾，字符结尾三种状况归一考虑，减少额外的判断
 */

class Solution {
   public:
    int countSegments(string s) {
        int ans = 0;
        s += " ";
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] != ' ' && s[i + 1] == ' ') ans++;
        return ans;
    }
};