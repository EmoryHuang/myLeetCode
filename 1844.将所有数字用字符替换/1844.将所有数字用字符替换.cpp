/*
 * @Descroption: LeetCode 1844. 将所有数字用字符替换
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:19:58
 * @解题思路:
 * 简单题，遍历字符串，若下标为奇数则对其进行替换
 */

class Solution {
   public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 1) s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};