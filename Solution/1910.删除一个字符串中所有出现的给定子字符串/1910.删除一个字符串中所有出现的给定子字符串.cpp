/*
 * @Descroption: LeetCode 1910. ɾ��һ���ַ��������г��ֵĸ������ַ���
 * @Author: EmoryHuang
 * @Date: 2021-07-22 18:53:19
 * @����˼·:
 * �����ַ�����part���ֵ�λ�ã��滻Ϊ��
 */

class Solution {
   public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) 
            s = s.replace(s.find(part), part.size(), "");
        return s;
    }
};