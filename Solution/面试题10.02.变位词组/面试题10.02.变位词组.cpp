/*
 * @Descroption: ������ 10.02. ��λ����
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:00:49
 * @����˼·:
 * ʹ�ó���Ϊ 26 �������¼ÿ����ĸ���ֵĴ���
 * Ȼ���Դ���Ϊ��ֵ���ж��ַ��Ƿ�Ϊͬ��
 */

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for (auto str : strs) {
            string cnt = string(26, '0');
            for (auto c : str) cnt[c - 'a']++;
            hash[cnt].push_back(str);
        }
        for (auto str : hash) ans.push_back(str.second);
        return ans;
    }
};