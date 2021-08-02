/*
 * @Descroption: LeetCode 785. �ж϶���ͼ
 * @Author: EmoryHuang
 * @Date: 2021-08-02 15:00:43
 * @Method:
 * Ⱦɫ���ж϶���ͼ
 * ��������ѡȡһ��δȾɫ�ĵ����Ⱦɫ��Ȼ���Խ������ڵĵ�Ⱦ���෴����ɫ��
 * ����ڽӵ��Ѿ���Ⱦɫ�������е�Ⱦɫ����Ӧ�ñ�Ⱦ����ɫ��ͬ����ô��˵�����Ƕ���ͼ
 */

class Solution {
   public:
    vector<int> color;  // 0��ʾδȾɫ��1��ʾ��ɫ��2��ʾ��ɫ
    bool dfs(vector<vector<int>>& graph, int u, int c) {
        // u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
        color[u] = c;
        // ����u���ڽӽڵ�
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            // ������ڽڵ�δȾɫ
            if (color[v] == 0) {
                // �����ڵĵ�Ⱦ���෴����ɫ
                if (!dfs(graph, v, 3 - c)) return false;
            } else if (color[v] == c)
                //���v�Ѿ���ɫ���Һͽ��u��ɫ��ͻ
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n);
        bool flag = true;
        for (int i = 0; i < n; i++)
            // �����ǰ�ڵ�δȾɫ
            if (color[i] == 0)
                if (!dfs(graph, i, 1)) {
                    flag = false;
                    break;
                }
        return flag;
    }
};