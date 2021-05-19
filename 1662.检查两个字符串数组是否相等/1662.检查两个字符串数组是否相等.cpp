/*
 * @Descroption: LeetCode 1662. 检查两个字符串数组是否相等
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:36:31
 * @解题思路:
 * 简单题，遍历两个数组，拼接为一个字符串
 */

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (auto word : word1) s1 += word;
        for (auto word : word2) s2 += word;
        return s1 == s2;
    }
};