/*
 * @Descroption: LeetCode 187. �ظ���DNA����
 * @Author: EmoryHuang
 * @Date: 2021-10-08 16:37:06
 * @Method:
 * �������� + ��ϣ��
 * �������ڴ�СΪ10��ʹ�ù�ϣ���¼�����г��ֵĴ���
 */

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> ans;
        for (int i = 0; i + 10 <= s.length(); i++) {
            string cur = s.substr(i, 10);
            if (hash[cur] == 1) ans.push_back(cur);
            hash[cur]++;
        }
        return ans;
    }
};