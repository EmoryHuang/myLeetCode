/*
 * @Descroption: LeetCode 347. 前 K 个高频元素
 * @Author: EmoryHuang
 * @Date: 2021-06-11 17:05:00
 * @解题思路:
 * 使用小根堆存储出现频率前 k 高的元素
 */

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int num : nums) mp[num]++;
        for (auto p : mp) {
            q.push(make_pair(p.second, p.first));
            if (q.size() > k) q.pop();
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};