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
        int num = 0;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0) q.push(i);
        while (!q.empty()) {
            num++;
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
        }
        return num == numCourses;
    }
};