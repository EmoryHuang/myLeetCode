/*
 * @Descroption: LeetCode 844. 比较含退格的字符串
 * @Author: EmoryHuang
 * @Date: 2021-06-13 16:17:00
 * @解题思路:
 * 模拟的方法，遇到 # 就删除字符
 */

class Solution {
   public:
    string backspace(string s) {
        string a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#')
                a += s[i];
            else if (s[i] == '#' && a.size() > 0)
                a.pop_back();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        return backspace(s) == backspace(t); 
    }
};