/*
 * @Descroption: LeetCode 451. �����ַ�����Ƶ������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:51:36
 * @����˼·:
 * ���� �ַ�->���� ��ӳ�䣬�� hashmap װ�� vector �н������򣬰�Ƶ�ʽ���������� string ����ƴ��
 */

class Solution {
   public:
    static bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto c : s) mp[c]++;  // ӳ��
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        string ans;
        for (auto c : v) ans += string(c.second, c.first);  //�ַ���ƴ��
        return ans;
    }
};