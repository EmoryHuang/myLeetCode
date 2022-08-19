/*
 * @Descroption: LeetCode 1807. �滻�ַ����е���������
 * @Author: EmoryHuang
 * @Date: 2021-09-24 19:07:52
 * @Method:
 * ��ϣ��
 * �����ַ������������������ȡ key ����ȡ��Ӧ�� value
 * �� key ���������� ?
 */

class Solution {
   public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for (auto p : knowledge) hash[p[0]] = p[1];
        string ans;
        int i = 0;
        while (i < s.size()) {
            string key;
            if (s[i] == '(') {
                i++;
                while (s[i] != ')') key += s[i++];
                // �������ڼ�ֵ
                if (hash.count(key) == 0)
                    ans += '?';
                else
                    ans += hash[key];
            } else if (s[i] != ')')
                ans += s[i];
            i++;
        }
        return ans;
    }
};