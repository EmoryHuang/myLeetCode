/*
 * @Descroption: LeetCode 1207. ��һ�޶��ĳ��ִ���
 * @Author: EmoryHuang
 * @Date: 2021-06-21 21:01:00
 * @����˼·:
 * ���⣬ʹ��map��¼���ֳ��ֵĴ�����Ȼ����set�ų��ظ���
 */

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for (int num : arr) mp[num]++;
        set<int> st;
        for (auto x : mp) st.insert(x.second);
        return st.size() == mp.size();
    }
};