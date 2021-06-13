/*
 * @Descroption: LeetCode 844. �ȽϺ��˸���ַ���
 * @Author: EmoryHuang
 * @Date: 2021-06-13 16:17:00
 * @����˼·:
 * ģ��ķ��������� # ��ɾ���ַ�
 */

class Solution {
   public:
    string backspace(string s) {
        string a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#')
                a += s[i];
            else if (s[i] == '#' && a.size() > 0)
                a.pop_back();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        return backspace(s) == backspace(t); 
    }
};