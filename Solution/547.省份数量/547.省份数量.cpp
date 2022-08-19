/*
 * @Descroption: LeetCode 547. ʡ������
 * @Author: EmoryHuang
 * @Date: 2021-08-01 13:56:25
 * @Method:
 * �������⣬����ͨ������
 * ����һ�����鼯
 * �����������������ͬ����ͨ��������ϲ�
 * ��������dfs
 * �������г��У�����ÿ�����У�����ó�����δ�����ʹ�����Ӹó��п�ʼ�����������
 * ������ȫ�������Ժ󣬼��ɵõ���ͨ����������
 */

class Solution {
   public:
    // ����һ�����鼯
    vector<int> parent;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) parent.push_back(i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j] == 1) _union(i, j);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;
        return ans;
    }

    // ��������dfs
    // vector<int> vis;
    // void dfs(vector<vector<int>>& isConnected, int i) {
    //     for (int j = 0; j < isConnected.size(); j++) {
    //         if (isConnected[i][j] == 1 && vis[j] == 0) {
    //             vis[j] = 1;
    //             dfs(isConnected, j);
    //         }
    //     }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     int ans = 0;
    //     vis.resize(n);
    //     for (int i = 0; i < n; i++)
    //         if (vis[i] == 0) {
    //             dfs(isConnected, i);
    //             ans++;
    //         }
    //     return ans;
    // }
};