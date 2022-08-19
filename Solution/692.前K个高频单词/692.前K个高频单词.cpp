/*
 * @Descroption: LeetCode 692. 前 K 个高频单词
 * @Author: EmoryHuang
 * @Date: 2021-05-01 20:12:36
 * @解题思路:
 * HashMap 统计各个单词的频率，然后将元素放入 vector 中，使用 sort()排序，最后取前`k`个
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
        for (auto w : words) mp[w]++;                       // 哈希表
        vector<pair<string, int>> p(mp.begin(), mp.end());  // 创建数组
        vector<string> ans;
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < k; i++) ans.push_back(p[i].first);  // 取前k个
        return ans;
    }
};