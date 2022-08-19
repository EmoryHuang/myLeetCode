/*
 * @Descroption: LeetCode 1576. �滻���е��ʺ�
 * @Author: EmoryHuang
 * @Date: 2022-01-05 08:53:52
 * @Method:
 * ���⣬�����ʺ�ʱ��������ǰ�������ַ�
 * ֻҪȡ���ⲻͬ���ַ��Ϳ���
 * ͷβ���ʺű��⿼�Ǳ߽����
 * */

class Solution {
   public:
    string modifyString(string s) {
        // ͷβ���ʺű��⿼�Ǳ߽����
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