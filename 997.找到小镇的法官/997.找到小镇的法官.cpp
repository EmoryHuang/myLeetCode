class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> degree(n + 1, vector<int>(2));  // 每个结点的度
        for (auto t : trust) {
            degree[t[0]][0]++;  // 出度
            degree[t[1]][1]++;  // 入度
        }
        for (int i = 1; i <= n; i++) {  // 出度为 0 入度为 N-1 的就是法官
            if (degree[i][0] == 0 && degree[i][1] == n - 1) return i;
        }
        return -1;
    }
};