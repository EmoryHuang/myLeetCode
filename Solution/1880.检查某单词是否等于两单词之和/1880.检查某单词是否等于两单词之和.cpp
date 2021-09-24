/*
 * @Descroption: LeetCode 1880. 检查某单词是否等于两单词之和
 * @Author: EmoryHuang
 * @Date: 2021-09-24 19:23:34
 * @Method:
 * 简单题，将字母转换成对应数字即可
 */

class Solution {
   public:
    int tonum(string s) {
        int n = s.size(), num = 0;
        for (int i = 0; i < n; i++) num = num * 10 + s[i] - 'a';
        return num;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return tonum(firstWord) + tonum(secondWord) == tonum(targetWord);
    }
};