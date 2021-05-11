class Solution {
   public:
    void dfs(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
             vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {            // 方案可行
            vector<string> board;  // 生成棋盘
            for (int i = 0; i < n; i++) {
                string line = string(n, '.');
                line[queens[i]] = 'Q';
                board.push_back(line);
            }
            solutions.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                queens[row] = i;
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(solutions, queens, n, row + 1, col, diag, undiag);  // 递归
                queens[row] = -1;                                       // 回溯
                col[i] = false;
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // col diag undiag 分别表示列，对角线，反对角线上是否有皇后
        vector<bool> col(n), diag(n), undiag(n);
        vector<vector<string>> solutions;  // 记录解法
        vector<int> queens(n, -1);         // 记录皇后位置
        dfs(solutions, queens, n, 0, col, diag, undiag);
        return solutions;
    }
};