/*
 * @Descroption: LeetCode 815. ����·��
 * @Author: EmoryHuang
 * @Date: 2021-06-28 13:42:00
 * @����˼·:
 * BFS��������·��Ȼ���ٸ�����·�ҳ�վ
 * ʹ�� map ��¼ (վ���ţ�[վ�����ڵ�·�߱��])
 * ����������ȵķ�����������ǰվ�����ڵ�·�ߣ�����ǰ·��δ���ʣ����������·�ߵ�����վ��
 * ���ҵ��� target����ô�ͷ����Ѿ�������·�ߵ���Ŀ
 */

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        queue<int> q;
        unordered_map<int, vector<int>> map;  // (վ���ţ�[վ�����ڵ�·�߱��])
        vector<int> vis(n);                   // ��¼·���Ƿ����
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (auto station : routes[i]) map[station].push_back(i);
        q.push(source);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int cur = q.front();  // ��ǰվ��
                q.pop();
                for (auto route : map[cur]) {  // ������ǰվ�����ڵ�·��
                    if (!vis[route]) {         // ����ǰ·��δ����
                        vis[route] = 1;
                        // ��������·�ߵ�����վ��
                        for (auto station : routes[route]) {
                            // ���� target
                            if (station == target) return ans;
                            q.push(station);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};