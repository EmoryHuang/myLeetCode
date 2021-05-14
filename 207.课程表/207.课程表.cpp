/*
 * @Descroption: LeetCode 207. �γ̱�
 * @Author: EmoryHuang
 * @Date: 2021-05-13 19:40:36
 * @����˼·: ��������
 * ʹ���ڽӱ�洢ͼ����ʼʱ���������Ϊ 0 �Ľڵ㶼����������У����Ǿ��ǿ�����Ϊ����������ǰ��Ľڵ�
 * �ڹ������������ÿһ���У�ȡ�����׵Ľڵ� u�������� u ���ڽӽ�㣬�����Ϊ 0�������
 */

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses);
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        queue<int> q;
        int num = 0;  // ��¼�����������еĶ�����
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0) q.push(i);  // �����Ϊ0�Ķ������
        while (!q.empty()) {
            num++;
            int u = q.front();  // ȡ������Ԫ��
            q.pop();
            for (auto v : adj[u]) {
                inDegree[v]--;                    // v����ȼ�1
                if (inDegree[v] == 0) q.push(v);  // ���Ϊ0�����
            }
        }
        return num == numCourses;
    }
};