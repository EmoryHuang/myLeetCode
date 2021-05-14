/*
 * @Descroption: LeetCode 56. 合并区间
 * @Author: EmoryHuang
 * @Date: 2021-05-11 14:56:36
 * @解题思路: 将列表中的区间按照左端点升序排序
 * 如果当前区间的左端点在数组ans中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组ans的末尾
 * 否则重合，更新数组 ans 中最后一个区间的右端点，将其置为二者的较大值。
 */

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());  // 按起点从小到大排序
        vector<vector<int>> ans;
        for (auto s : intervals) {
            int start = s[0], end = s[1];
            // 如果是第一个区间或者区间不重叠
            if (!ans.size() || ans.back()[1] < start) {
                ans.push_back({start, end});              // 记录区间
            } else                                        // 如果区间有重叠
                ans.back()[1] = max(ans.back()[1], end);  // 取最大的结束位置
        }
        return ans;
    }
};