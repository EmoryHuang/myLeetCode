/*
 * @Descroption: LeetCode 847. �������нڵ�����·��
 * @Author: EmoryHuang
 * @Date: 2021-08-06 15:26:15
 * @Method:
 * BFS + ״̬ѹ��
 * Ϊ�˱�ʶ���еķ���״̬��ʹ��״̬ѹ������һλ��ʾһ���ڵ��Ƿ����
 * ����Ϊ����ʱ��mask = (000) = 0����������ʱ��mask = (111) = 2^n - 1
 * ͬ���ģ����µ� i ���ڵ��״̬ʱ��next_mask = mask | (1 << i)
 * �ص���Ŀ��һ��ʼ��������㲻ȷ������˽����нڵ�����
 * ʹ��BFS���ж�����ı���
 */

class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        // ������㲻ȷ�������visΪn��2^n�У��Լ�¼ÿ����״̬
        vector<vector<bool>> vis(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            // ���ڵ����id��״̬mask�;���dis���
            // ״̬maskʹ��λ��ʶÿ���ڵ��Ƿ����
            q.push({i, 1 << i, 0});
            vis[i][1 << i] = true;
        }
        while (!q.empty()) {
            auto [id, mask, dis] = q.front();
            q.pop();
            // ����Ѿ�������ȫ���ڵ㣬��״̬Ϊ 2^n - 1
            if (mask == (1 << n) - 1) return dis;
            for (auto ne : graph[id]) {
                // ������õ���һ��״̬
                int next_mask = mask | 1 << ne;
                if (!vis[ne][next_mask]) {
                    q.push({ne, next_mask, dis + 1});
                    vis[ne][next_mask] = true;
                }
            }
        }
        return 0;
    }
};