/*
 * @Descroption: LeetCode 58. ���һ�����ʵĳ���
 * @Author: EmoryHuang
 * @Date: 2021-03-18 20:35:36
 * @����˼·: ���⣬�����ַ�����ע��ȥ��ĩβ�ո�
 */

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int count = 0, i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;  //ȥ��ĩβ�ո�
        while (i >= 0 && s[i--] != ' ') count++;
        return count;
    }
};