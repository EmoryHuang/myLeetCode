class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        int flag = false;
        for (auto p : intervals) {
            if (p[0] > r) { // 在区间右侧且无交集
                if (!flag) {
                    ans.push_back({l, r});
                    flag = true;
                }
                ans.push_back(p);
            } else if (p[1] < l) {  // 在区间左侧且无交集
                ans.push_back(p);
            } else {  // 有交集
                l = min(l, p[0]);
                r = max(r, p[1]);
            }
        }
        if (!flag) ans.push_back({l, r});
        return ans;
    }
};