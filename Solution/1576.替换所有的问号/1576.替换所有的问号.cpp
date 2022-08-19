/*
 * @Descroption: LeetCode 1576. 替换所有的问号
 * @Author: EmoryHuang
 * @Date: 2022-01-05 08:53:52
 * @Method:
 * 简单题，遇到问号时，考虑其前后两个字符
 * 只要取任意不同的字符就可以
 * 头尾加问号避免考虑边界情况
 * */

class Solution {
   public:
    string modifyString(string s) {
        // 头尾加问号避免考虑边界情况
        s = '?' + s + '?';
        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == '?') {
                for (int j = 97; j < 123; j++)
                    if (s[i + 1] != j && s[i - 1] != j) {
                        s[i] = j;
                        break;
                    }
            }
        }
        return s.substr(1, s.length() - 2);
    }
};