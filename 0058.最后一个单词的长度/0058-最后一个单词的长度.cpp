/*
 * @Descroption: LeetCode 58. 最后一个单词的长度
 * @Author: EmoryHuang
 * @Date: 2021-03-18 20:35:36
 * @解题思路: 简单题，遍历字符串，注意去除末尾空格
 */

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int count = 0, i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;  //去除末尾空格
        while (i >= 0 && s[i--] != ' ') count++;
        return count;
    }
};