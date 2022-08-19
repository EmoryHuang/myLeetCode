/*
 * @Descroption: LeetCode 407. 接雨水 II
 * @Author: EmoryHuang
 * @Date: 2021-11-03 16:16:50
 * @Method:
 * 优先队列
 * 维护一个小根堆
 * 确保当前出队的元素对于该中心块来说是它周围四个高度中的最小值，那么就能确定接雨水的大小
 * 首先将边缘加入优先队列，而后不断往内部缩小外围
 * 如果外围的高度大于当前高度，那么可以灌水
 */


class Solution {
   public:
    typedef pair<int, pair<int, int>> piii;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        // 维护一个小根堆
        //  确保当前出队的元素对于该中心块来说是它周围四个高度中的最小值
        //  那么就能确定接雨水的大小
        priority_queue<piii, vector<piii>, greater<piii>> heap;
        // vis 标记是否访问
        vector<vector<int>> vis(m, vector<int>(n));
        int ans = 0;
        // 将边缘加入优先队列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    heap.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        while (!heap.empty()) {
            auto [h, p] = heap.top();
            heap.pop();
            int i = p.first, j = p.second;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    // 如果外围的高度大于当前高度，那么可以灌水
                    if (h > heightMap[x][y]) ans += h - heightMap[x][y];
                    heap.push({max(h, heightMap[x][y]), {x, y}});
                    vis[x][y] = 1;
                }
            }
        }
        return ans;
    }
};