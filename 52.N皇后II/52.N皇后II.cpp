class Solution {
   public:
    int ans = 0;
    void dfs(int n, int row, vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {  // 方案可行
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(n, row + 1, col, diag, undiag);
                col[i] = false;  // 回溯
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        // col diag undiag 分别表示列，对角线，反对角线上是否有皇后
        vector<bool> col(n), diag(n), undiag(n);
        dfs(n, 0, col, diag, undiag);
        return ans;
    }
};