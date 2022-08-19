/*
 * @Descroption: LeetCode 684. ��������
 * @Author: EmoryHuang
 * @Date: 2021-08-01 14:31:49
 * @Method:
 * ���鼯
 * ����������㲻λ��ͬһ����ͨ�����У���ô�ϲ����������㲻�ᵼ�»��ĳ���
 * ���λ��ͬһ����ͨ�����У���ô�ϲ�����������ᵼ�»��ĳ���
 */

class Solution {
   public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n + 1; i++) parent.push_back(i);
        for (auto edge : edges) {
            // �����λ��ͬһ����ͨ������
            // ��ô�ϲ����������㲻�ᵼ�»��ĳ���
            if (find(edge[0]) != find(edge[1])) 
                _union(edge[0], edge[1]);
            // ���λ��ͬһ����ͨ������
            // ��ô�ϲ�����������ᵼ�»��ĳ���
            else
                return {edge[0], edge[1]};
        }
        return {};
    }
};