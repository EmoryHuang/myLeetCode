/*
 * @Descroption: LeetCode 1288. ɾ������������
 * @Author: EmoryHuang
 * @Date: 2021-09-15 18:49:06
 * @Method:
 * ����
 * �� intervals ��һ������С���󣬵ڶ������Ӵ�С
 * Ȼ����� intervals �� pre_l <= l and pre_r >= r ����Ϊ�Ǹ���
 */

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        vector<pair<int, int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        for (auto p : intervals) {
            auto [pre_l, pre_r] = ans.back();
            if (pre_l <= p[0] && pre_r >= p[1]) continue;
            ans.push_back({p[0], p[1]});
        }
        return ans.size();
    }
};