/*
 * @Descroption: LeetCode 210. �γ̱� II
 * @Author: EmoryHuang
 * @Date: 2021-10-23 14:46:05
 * @Method:
 * ��������
 * ά��һ�����У������Ϊ 0 �Ľڵ���ӣ�Ȼ�������ӵĽڵ���ȼ�һ
 * ֱ������Ϊ��
 */

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> indegree(numCourses);
        vector<int> ans;
        // �����ڽӱ�
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        // �����Ϊ 0 �Ľڵ����
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : edges[u])
                if (--indegree[v] == 0) q.push(v);
        }
        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};