/*
 * @Descroption: LeetCode 205. ͬ���ַ���
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:40:36
 * @����˼·: �ж� s �� t ÿ��λ���ϵ��ַ��Ƿ�һһ��Ӧ���� s ������һ���ַ��� t ��Ψһ���ַ���Ӧ��
 * ͬʱ t ������һ���ַ��� s ��Ψһ���ַ���Ӧ
 */

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) != t.find(t[i])) {  //������λ�ò�ͬ
                return false;
            }
        }
        return true;
    }
};