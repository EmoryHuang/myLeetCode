/*
 * @Descroption: LeetCode 1334. ��ֵ�������ھ����ٵĳ���
 * @Author: EmoryHuang
 * @Date: 2021-08-02 16:30:44
 * @Method:
 * ת��һ����˼��Ҳ������һ��Դ�㣬������ֵ���ܹ�����ĳ�����������
 * �������г�����ΪԴ�㣬ʹ��spfa�㷨��Floyd, Djistra�������·��
 */

class Solution {
   public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // �����ڽӱ�
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        int ans = -1, mincnt = INT_MAX;
        // �������г�����ΪԴ��
        for (int i = 0; i < n; i++) {
            // spfa �㷨������С����
            vector<int> dis(n, INT_MAX);
            vector<bool> inq(n);
            queue<int> q;
            q.push(i);
            inq[i] = true;
            dis[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                inq[u] = false;
                for (int j = 0; j < mp[u].size(); j++) {
                    int v = mp[u][j].first;
                    int w = mp[u][j].second;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            q.push(v);
                            inq[v] = true;
                        }
                    }
                }
            }
            int cnt = 0;
            for (int k = 0; k < n; k++)
                if (dis[k] <= distanceThreshold) cnt++;
            // �����ھ����ٵĳ���
            if (cnt <= mincnt) {
                mincnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};