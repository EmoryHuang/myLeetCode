/*
 * @Descroption: LeetCode 451. 根据字符出现频率排序
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:51:36
 * @解题思路:
 * 建立 字符->个数 的映射，将 hashmap 装到 vector 中进行排序，按频率降序，最后利用 string 进行拼接
 */

class Solution {
   public:
    static bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto c : s) mp[c]++;  // 映射
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        string ans;
        for (auto c : v) ans += string(c.second, c.first);  //字符串拼接
        return ans;
    }
};