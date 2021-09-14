/*
 * @Descroption: LeetCode 524. ͨ��ɾ����ĸƥ�䵽�ֵ��������
 * @Author: EmoryHuang
 * @Date: 2021-09-14 11:29:25
 * @Method:
 * ˫ָ�� + ����
 * p, q �ֱ�Ϊָ�� s �� word ��ָ��
 * ���ַ���ȣ���p��q�����ƶ�������p�����ƶ�
 * ����ҵ���һ���ַ���������� ans
 * �����Ⱥ��ֵ������� ans
 */

class Solution {
   public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> ans;
        for (auto word : dictionary) {
            int p = 0, q = 0;
            while (p < s.size() && q < word.size()) {
                if (s[p] == word[q])
                    p++, q++;
                else
                    p++;
                if (q == word.size()) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end(), [](string a, string b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a < b;
        });
        return ans.empty() ? "" : ans[0];
    }
};