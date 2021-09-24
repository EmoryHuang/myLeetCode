/*
 * @Descroption: LeetCode 1880. ���ĳ�����Ƿ����������֮��
 * @Author: EmoryHuang
 * @Date: 2021-09-24 19:23:34
 * @Method:
 * ���⣬����ĸת���ɶ�Ӧ���ּ���
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