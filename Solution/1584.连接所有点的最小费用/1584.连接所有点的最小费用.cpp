/*
 * @Descroption: LeetCode 1584. 连接所有点的最小费用
 * @Author: EmoryHuang
 * @Date: 2021-06-20 15:33:00
 * @解题思路:
 * kruskal算法
 * 计算所有点之间的距离，然后从小到大进行排序
 * 利用并查集构建最小生成树，如果当前边的两个点没有不在最小生成树中，则将该边添加到最小生成树中，更新边数和费用
 */

class Solution {
   public:
    struct Edge {
        int i, j, c;
    };
    vector<int> parent;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> mp;
        // 初始化并查集
        for (int i = 0; i < n; i++) parent.push_back(i);
        // 计算所有点之间的距离
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                mp.push_back({i, j, abs(x1 - x2) + abs(y1 - y2)});
            }
        }
        // 按距离从小到大排序
        sort(mp.begin(), mp.end(), [](const auto& a, const auto& b) { return a.c < b.c; });
        int edge = 0, cost = 0;  // 记录边数和总花费
        for (auto p : mp) {
            int a = find(p.i);
            int b = find(p.j);
            if (a != b) {       //如果不在一个集合
                parent[a] = b;  // 合并
                edge++;
                cost += p.c;
                if (edge == n - 1) break;
            }
        }
        return cost;
    }
};