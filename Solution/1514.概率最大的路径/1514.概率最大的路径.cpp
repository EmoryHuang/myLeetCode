/*
 * @Descroption: LeetCode 1514. ��������·��
 * @Author: EmoryHuang
 * @Date: 2021-06-16 13:47:00
 * @����˼·:
 * spfa�㷨
 * ���ڽӾ���洢ͼ
 * ��ø�������·��
 */

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start,
                          int end) {
        vector<vector<pair<int, double>>> mp(n);
        vector<double> d(n, 0);
        vector<int> inq(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            mp[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        queue<int> q;
        q.push(start);
        inq[start] = 1;  // ����ڶ�����
        d[start] = 1;    // ��㵽����ĸ���Ϊ1
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;  // u���ڶ�����
            // �����ڽӽڵ�
            for (int j = 0; j < mp[u].size(); j++) {
                int v = mp[u][j].first;
                double dis = mp[u][j].second;
                if (d[v] < d[u] * dis) {  // ���ʸ����·��
                    d[v] = d[u] * dis;
                    if (!inq[v]) {  // ���v���ڶ�����
                        q.push(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        return d[end];
    }
};