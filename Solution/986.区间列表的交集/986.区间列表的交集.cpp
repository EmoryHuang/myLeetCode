/*
 * @Descroption: LeetCode 986. 区间列表的交集
 * @Author: EmoryHuang
 * @Date: 2021-06-06 15:50:00
 * @解题思路:
 * 用两个指针，分别扫描 A、B 数组，根据子区间的左右端，求出一个交集区间
 * 交集区间的左端，取它们的较大者
 * 交集区间的右端，取它们的较小者
 * 求完一个交集区间后，较早结束的子区间，指针移动
 */

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if (left <= right) ans.push_back({left, right});  // 取交集
            // 右端大的右移
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};