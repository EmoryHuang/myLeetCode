/*
 * @Descroption: LeetCode 436. 寻找右区间
 * @Author: EmoryHuang
 * @Date: 2022-05-20 09:03:42
 * @Method:
 * 二分查找
 * 由于每个间隔的起点都不相同，因此将起点进行存储同时记录原始位置存储在 idx，按照左边界排序
 * 枚举右端点，使用二分查找 idx 中大于等于 intervals[i][1] 的最小值
 */

class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> idx;
        // 由于每个间隔的起点都不相同，因此将起点进行存储并记录原始位置
        for (int i = 0; i < n; i++) idx.push_back({intervals[i][0], i});
        // 按照左边界排序
        sort(idx.begin(), idx.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            // 枚举右端点，使用二分查找 idx 中大于等于 intervals[i][1] 的最小值
            auto it = lower_bound(idx.begin(), idx.end(), make_pair(intervals[i][1], 0));
            if (it != idx.end()) ans[i] = it->second;
        }
        return ans;
    }
};