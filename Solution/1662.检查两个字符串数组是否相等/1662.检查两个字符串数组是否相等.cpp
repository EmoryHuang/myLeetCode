/*
 * @Descroption: LeetCode 1662. ��������ַ��������Ƿ����
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:36:31
 * @����˼·:
 * ���⣬�����������飬ƴ��Ϊһ���ַ���
 */

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (auto word : word1) s1 += word;
        for (auto word : word2) s2 += word;
        return s1 == s2;
    }
};