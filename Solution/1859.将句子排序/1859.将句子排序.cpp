/*
 * @Descroption: LeetCode 1859. 将句子排序
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:08:00
 * @解题思路:
 * 简单题，直接把单词尾部的数字当下标用，存入哈希表
 */

class Solution {
   public:
    string sortSentence(string s) {
        vector<string> order(10);
        string str = " ";
        for (auto c : s) {
            if (isalpha(c)) str += c;
            if (isdigit(c)) {
                order[c - '0'] = str;
                str = " ";
            }
        }
        string ans;
        for (auto c : order) ans += c;
        ans.erase(0, 1);  // 去除第一个空格
        return ans;
    }
};