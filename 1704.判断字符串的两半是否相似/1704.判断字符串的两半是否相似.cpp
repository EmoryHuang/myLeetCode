/*
 * @Descroption: LeetCode 1704. �ж��ַ����������Ƿ�����
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:03:31
 * @����˼·:
 * �����ַ���������ǰ�벿�ֺͺ�벿�ֵ�Ԫ����ĸ����
 */

class Solution {
   public:
    bool halvesAreAlike(string s) {
        string str = "aeiouAEIOU";
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (str.find(s[i]) != string::npos) 
                flag = i < s.size() / 2 ? flag + 1 : flag - 1;
        }
        return flag == 0;
    }
};