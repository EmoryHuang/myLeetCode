/*
 * @Descroption: LeetCode 1816. 截断句子
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:27:00
 * @解题思路:
 * 简单题，数空格
 */

class Solution {
   public:
    string truncateSentence(string s, int k) {
        string ans;
        for (auto c : s) {
            if (c == ' ') k--;
            if (k == 0) return ans;
            ans += c;
        }
        return ans;
    }
};