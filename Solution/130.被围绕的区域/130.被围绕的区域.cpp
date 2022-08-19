/*
 * @Descroption: LeetCode 130. ��Χ�Ƶ�����
 * @Author: EmoryHuang
 * @Date: 2021-09-13 20:41:50
 * @Method:
 * dfs/bfs
 * �ӱ߽� O �������ҵ�������߽� O ���ڵ� O�����Ϊ #
 * Ȼ���ٴα������󣬽�����ʣ�µ� O תΪ X��# תΪ O
 */

class Solution {
   public:
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
            board[i][j] = '#';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};