/*
 * @Descroption: LeetCode 802. �ҵ����յİ�ȫ״̬
 * @Author: EmoryHuang
 * @Date: 2021-08-05 14:17:50
 * @Method:
 * ����ͼ + ��������
 * ͳ��ÿ���ڵ�ĳ��ȣ�����ͼ�洢Ϊ����ͼ
 * ���Ƚ�����Ϊ 0 �Ľڵ����
 * ͨ���������򣬲���ȥ���ߣ�Ȼ�󽫳���Ϊ 0 �Ľڵ����
 * ���ͳ�Ƴ���Ϊ 0 �Ľڵ�
 */

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> mp;
        vector<int> outdegree(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            // ͳ�����нڵ�ĳ���
            outdegree[i] = graph[i].size();
            if (!outdegree[i])
                // ������Ϊ 0 �Ľڵ����
                q.push(i);
            else
                // ��������ͼ
                for (int node : graph[i]) mp[node].push_back(i);
        }
        // ��������
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int ne : mp[node]) {
                if (--outdegree[ne] == 0) q.push(ne);
            }
        }
        vector<int> ans;
        // ͳ�Ƴ���Ϊ 0 �Ľڵ�
        for (int i = 0; i < n; i++)
            if (!outdegree[i]) ans.push_back(i);
        return ans;
    }
};