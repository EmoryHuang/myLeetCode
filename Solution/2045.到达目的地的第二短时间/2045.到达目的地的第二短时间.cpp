/*
 * @Descroption: LeetCode 2045. ����Ŀ�ĵصĵڶ���ʱ��
 * @Author: EmoryHuang
 * @Date: 2022-01-24 18:31:48
 * @Method:
 * BFS
 * ͬʱά�����·�ʹζ�·���� d < min_d[x]�������� min_d[x] ���� sec_d[x]������ d ���� min_d[x]
 * �� min_d[x] < d < sec_d[x]������ d ���� sec_d[x]
 * ���ں��̵Ƶ��л�����: ���� step ��
 * �� step % change Ϊ�棬��Ϊ��ƣ��ȴ�ʱ��Ϊ change - (step % change)
 * �� step % change Ϊż����Ϊ�̵ƣ��ȴ�ʱ��Ϊ 0
 * */

class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> map(n + 1);
        for (auto& edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        // min_d �� sec_d �ֱ��ʾ�� 1 �� i ����С�͵ڶ�С��·������
        vector<int> min_d(n + 1, 0x3f3f3f3f), sec_d(n + 1, 0x3f3f3f3f);
        min_d[1] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
            auto [u, dis] = q.front();
            q.pop();
            for (auto v : map[u]) {
                int d = dis + 1;
                if (d < min_d[v]) {
                    sec_d[v] = min_d[v];
                    min_d[v] = d;
                    q.push({v, min_d[v]});
                    q.push({v, sec_d[v]});
                } else if (d < sec_d[v] && d > min_d[v]) {
                    sec_d[v] = d;
                    q.push({v, sec_d[v]});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sec_d[n]; i++) {
            int a = ans / change, b = ans % change;
            int wait = a % 2 == 0 ? 0 : change - b;
            ans += wait + time;
        }
        return ans;
    }
};