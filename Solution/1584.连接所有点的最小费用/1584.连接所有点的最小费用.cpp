/*
 * @Descroption: LeetCode 1584. �������е����С����
 * @Author: EmoryHuang
 * @Date: 2021-06-20 15:33:00
 * @����˼·:
 * kruskal�㷨
 * �������е�֮��ľ��룬Ȼ���С�����������
 * ���ò��鼯������С�������������ǰ�ߵ�������û�в�����С�������У��򽫸ñ���ӵ���С�������У����±����ͷ���
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
        // ��ʼ�����鼯
        for (int i = 0; i < n; i++) parent.push_back(i);
        // �������е�֮��ľ���
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                mp.push_back({i, j, abs(x1 - x2) + abs(y1 - y2)});
            }
        }
        // �������С��������
        sort(mp.begin(), mp.end(), [](const auto& a, const auto& b) { return a.c < b.c; });
        int edge = 0, cost = 0;  // ��¼�������ܻ���
        for (auto p : mp) {
            int a = find(p.i);
            int b = find(p.j);
            if (a != b) {       //�������һ������
                parent[a] = b;  // �ϲ�
                edge++;
                cost += p.c;
                if (edge == n - 1) break;
            }
        }
        return cost;
    }
};