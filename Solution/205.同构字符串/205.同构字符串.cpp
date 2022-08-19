/*
 * @Descroption: LeetCode 205. 同构字符串
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:40:36
 * @解题思路: 判断 s 和 t 每个位置上的字符是否都一一对应，即 s 的任意一个字符被 t 中唯一的字符对应，
 * 同时 t 的任意一个字符被 s 中唯一的字符对应
 */

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) != t.find(t[i])) {  //若出现位置不同
                return false;
            }
        }
        return true;
    }
};