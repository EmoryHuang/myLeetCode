class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());  // 按起点从小到大排序
        for (auto p : intervals) {
            int start = p[0], end = p[1];
            // 如果是第一个区间或者区间不重叠
            if (!ans.size() || ans.back()[1] < start) {
                ans.push_back({start, end});              // 记录区间
            } else                                        // 如果区间有重叠
                ans.back()[1] = max(ans.back()[1], end);  // 取最大的结束位置
        }
        return ans;
    }
};