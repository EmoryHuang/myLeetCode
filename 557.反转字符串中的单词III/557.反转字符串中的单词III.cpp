/*
 * @Descroption: LeetCode 557. 反转字符串中的单词 III
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:58:36
 * @解题思路: 简单题，原地算法
 * 用 `left` 标记单词的左边起点，若遇到空格，则反转 `left` 到 `i`，最后去掉多余的一个空格
 */

class Solution {
   public:
    string reverseWords(string s) {
        s += " ";
        int left = 0;  // 记录单词起点位置
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        s.erase(s.end() - 1);
        return s;
    }
};