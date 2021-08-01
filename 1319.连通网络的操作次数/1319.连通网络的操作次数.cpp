/*
 * @Descroption: LeetCode 1319. ��ͨ����Ĳ�������
 * @Author: EmoryHuang
 * @Date: 2021-08-01 14:08:48
 * @Method:
 * ���鼯����ͨ������
 * ÿ�ɹ�����һ�κϲ���������ͨ�������ͻ���� 1
 */

class Solution {
   public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) return -1;
        for (int i = 0; i < n; i++) parent.push_back(i);
        for (auto con : connections) _union(con[0], con[1]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;
        return ans - 1;
    }
};