/*
 * @Descroption: LeetCode 811. ���������ʼ���
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:08:00
 * @����˼·:
 * �������ǰ������֣�Ȼ��Ӻ���ǰ����
 * ʹ�ù�ϣ��洢ÿ�������ķ��ʴ���
 */

class Solution {
   public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        vector<string> ans;
        for (auto cpdomain : cpdomains) {
            int count = 0;
            // ��ȡǰ�������
            for (int i = 0; cpdomain[i] != ' '; i++) 
                count = count * 10 + (cpdomain[i] - '0');
            // �Ӻ���ǰ������ÿ����'.',�ͽ�������ϣ��
            int j = cpdomain.size() - 1;
            for (; cpdomain[j] != ' '; j--)
                if (cpdomain[j] == '.') 
                    mp[cpdomain.substr(j + 1)] += count;
            mp[cpdomain.substr(j + 1)] += count;
        }
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            ans.push_back(to_string(it->second) + " " + it->first);
        return ans;
    }
};