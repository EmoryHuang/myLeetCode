/*
 * @Descroption: LeetCode 212. µ¥´ÊËÑË÷ II
 * @Author: EmoryHuang
 * @Date: 2021-09-16 16:06:08
 * @Method:
 * ±©Á¦dfs
 */

class Solution {
   public:
    vector<string> ans;
    vector<vector<int>> vis;
    set<string> st;
    vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j, string cur) {
        if (cur.size() > 10) return;
        if (st.count(cur) == 1) {
            ans.push_back(cur);
            st.erase(cur);
        }
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                vis[x][y] = 1;
                cur += board[x][y];
                dfs(board, x, y, cur);
                vis[x][y] = 0;
                cur.pop_back();
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        vis.resize(m, vector<int>(n));
        for (auto word : words) st.insert(word);
        string cur = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 1;
                cur += board[i][j];
                dfs(board, i, j, cur);
                vis[i][j] = 0;
                cur.pop_back();
            }
        }
        return ans;
    }
};