/*
 * @Descroption: LeetCode 218. 天际线问题
 * @Author: EmoryHuang
 * @Date: 2021-07-13 20:09:14
 * @解题思路:
 * 维护一个大根堆，遍历所有端点
 * 如果是左端点，则将其高度加入大根堆
 * 如果是右端点，则将其高度移出大根堆
 * 每次取当前最大值与上一个最大值比较
 */

class Solution {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> points;
        // 为了方便排序，对于左端点，令高度为负；对于右端点令高度为正
        for (auto bulid : buildings) {
            int l = bulid[0], r = bulid[1], h = bulid[2];
            points.push_back({l, -h});
            points.push_back({r, h});
        }
        // 按照横坐标进行排序
        // 如果横坐标相同，则按照左端点排序
        // 如果相同的左/右端点，则按照高度进行排序
        sort(points.begin(), points.end());
        multiset<int> heap;
        int pre = 0;
        heap.insert(pre);
        // 遍历所有端点
        for (auto point : points) {
            int p = point[0], h = point[1];
            if (h < 0)
                heap.insert(-h);  // 如果是左端点，则加入大根堆
            else
                heap.erase(heap.find(h));  // 如果是右端点，则移出大根堆
            ;
            int cur = *heap.rbegin();  // 取当前最大值比较
            if (cur != pre) {
                ans.push_back({p, cur});
                pre = cur;
            }
        }
        return ans;
    }
};