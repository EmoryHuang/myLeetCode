/*
 * @Descroption: LeetCode 1910. 删除一个字符串中所有出现的给定子字符串
 * @Author: EmoryHuang
 * @Date: 2021-07-22 18:53:19
 * @解题思路:
 * 查找字符串中part出现的位置，替换为空
 */

class Solution {
   public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) 
            s = s.replace(s.find(part), part.size(), "");
        return s;
    }
};