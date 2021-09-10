/*
 * @Descroption: LeetCode 1207. 独一无二的出现次数
 * @Author: EmoryHuang
 * @Date: 2021-06-21 21:01:00
 * @解题思路:
 * 简单题，使用map记录数字出现的次数，然后用set排除重复数
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