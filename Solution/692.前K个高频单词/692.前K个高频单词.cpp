/*
 * @Descroption: LeetCode 692. ǰ K ����Ƶ����
 * @Author: EmoryHuang
 * @Date: 2021-05-01 20:12:36
 * @����˼·:
 * HashMap ͳ�Ƹ������ʵ�Ƶ�ʣ�Ȼ��Ԫ�ط��� vector �У�ʹ�� sort()�������ȡǰ`k`��
 */

class Solution {
   public:
    static bool cmp(pair<string, int> a, pair<string, int> b) {
        if (a.second != b.second)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (auto w : words) mp[w]++;                       // ��ϣ��
        vector<pair<string, int>> p(mp.begin(), mp.end());  // ��������
        vector<string> ans;
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < k; i++) ans.push_back(p[i].first);  // ȡǰk��
        return ans;
    }
};