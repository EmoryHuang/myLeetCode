/*
 * @Descroption: LeetCode 743. �����ӳ�ʱ��
 * @Author: EmoryHuang
 * @Date: 2021-08-02 14:10:16
 * @Method:
 * �� k ��������������� x ����̾�������ֵ
 * ����һ��SPFA�㷨
 * ��������Floyd�㷨
 * ������������dijkstra�㷨
 */

class Solution {
   public:
    // ����һ��SPFA�㷨
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // �����ڽӱ�
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            mp[u].push_back({v, w});
        }
        vector<int> d(n + 1, INT_MAX);  // ��һ���ڵ㲻����
        queue<int> q;
        vector<bool> inq(n + 1, false);
        d[k] = d[0] = 0;
        q.push(k);
        inq[k] = true;  // �ڵ��Ƿ��ڶ�����
        while (!q.empty()) {
            int u = q.front();  // ȡ����Ԫ��
            inq[u] = false;
            q.pop();
            // ������u���ڵĽڵ�
            for (int j = 0; j < mp[u].size(); j++) {
                int v = mp[u][j].first;   // �ڵ���
                int w = mp[u][j].second;  // ��Ȩ
                if (d[v] > d[u] + w) {    // ������̾���
                    d[v] = d[u] + w;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        for (int dis : d)
            if (dis == INT_MAX) return -1;
        return *max_element(d.begin(), d.end());
    }

    // ��������Floyd�㷨
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     int INF = 0x3f3f3f3f;
    //     vector<vector<int>> mp(n + 1, vector<int>(n + 1, INF));
    //     vector<bool> vis(n + 1, false);
    //     // �����ڽӾ���
    //     for (int i = 1; i <= n; i++) mp[i][i] = mp[i][0] = mp[0][i] = 0;
    //     for (auto time : times) {
    //         int u = time[0], v = time[1], w = time[2];
    //         mp[u][v] = w;
    //     }
    //     for (int t = 1; t <= n; t++)
    //         for (int i = 1; i <= n; i++)
    //             for (int j = 1; j <= n; j++) mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j]);
    //     for (int i = 1; i <= n; i++)
    //         if (mp[k][i] == INF) return -1;
    //     return *max_element(mp[k].begin(), mp[k].end());
    // }

    // ������������dijkstra�㷨
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     int INF = 0x3f3f3f3f;
    //     vector<vector<int>> mp(n + 1, vector<int>(n + 1, INF));
    //     vector<int> d(n + 1, INF);
    //     vector<bool> vis(n + 1, false);
    //     // �����ڽӾ���
    //     for (int i = 1; i <= n; i++) mp[i][i] = 0;
    //     for (auto time : times) {
    //         int u = time[0], v = time[1], w = time[2];
    //         mp[u][v] = w;
    //     }
    //     d[k] = d[0] = 0;  // ��㵽����ľ���Ϊ0
    //     for (int i = 1; i <= n; i++) {
    //         int u = -1;  // Ѱ�Ҿ�����С�ĵ�
    //         for (int j = 1; j <= n; j++) {
    //             if (!vis[j] && (u == -1 || d[u] > d[j])) u = j;
    //         }
    //         vis[u] = true;
    //         // ��uΪ�н��
    //         for (int v = 1; v <= n; v++) d[v] = min(d[v], d[u] + mp[u][v]);
    //     }
    //     for (int dis : d)
    //         if (dis == INF) return -1;
    //     return *max_element(d.begin(), d.end());
    // }
};