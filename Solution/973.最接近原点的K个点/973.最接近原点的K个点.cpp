/*
 * @Descroption: LeetCode 973. 最接近原点的 K 个点
 * @Author: EmoryHuang
 * @Date: 2021-08-19 20:08:56
 * @Method:
 * 方法一：直接排序
 * 方法二：堆
 * 可以使用一个大根堆实时维护前 k 个最小的距离平方
 * 将每个节点与原点的距离以及节点编号加入堆
 */

class Solution {
   public:
    // 方法一：直接排序
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     sort(points.begin(), points.end(),
    //          [](vector<int> a, vector<int> b) { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });
    //     return vector<vector<int>>(points.begin(), points.begin() + k);
    // }

    // 方法二：堆
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            int x = points[i][0], y = points[i][1];
            q.push({x * x + y * y, i});
        }
        for (int i = k; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int d = x * x + y * y;
            if (q.top().first > d) {
                q.pop();
                q.push({d, i});
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            auto [_, pos] = q.top();
            q.pop();
            ans.push_back(points[pos]);
        }
        return ans;
    }
};