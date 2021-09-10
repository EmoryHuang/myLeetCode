/*
 * @Descroption: 剑指 Offer 05. 替换空格
 * @Author: EmoryHuang
 * @Date: 2021-06-28 16:42:00
 * @解题思路:
 * 简单题，替换空格，遍历或者直接 replace
 */

class Solution {
   public:
    string replaceSpace(string s) {
        while (s.find(' ') != string::npos) s.replace(s.find(' '), 1, "%20");
        return s;
    }
};