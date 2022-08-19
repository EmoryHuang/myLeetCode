/*
 * @Descroption: LeetCode 419. 甲板上的战舰
 * @Author: EmoryHuang
 * @Date: 2021-12-18 08:50:23
 * @Method:
 * 方法一: dfs
 * 由于没有相邻的战舰，因此可以简单使用dfs, 并查集等方法解决
 *
 * 方法二: 一次扫描
 * 当且仅当某个 X 格子的「上方」&「左方」不为 X 时，该格子为战舰首个格子，可以进行计数
 * 同时注意边界问题
 * */

class Solution {
   public:
    // 方法一: dfs
    // vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    // void dfs(vector<vector<char>>& board, int i, int j) {
    //     board[i][j] = '.';
    //     for (int k = 0; k < 4; ++k) {
    //         int x = i + dx[k], y = j + dy[k];
    //         if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'X') {
    //             dfs(board, x, y);
    //         }
    //     }
    // }
    // int countBattleships(vector<vector<char>>& board) {
    //     int m = board.size(), n = board[0].size();
    //     int res = 0;
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (board[i][j] == 'X') {
    //                 dfs(board, i, j);
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 方法二: 一次扫描
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') continue;
                    if (j > 0 && board[i][j - 1] == 'X') continue;
                    res++;
                }
            }
        }
        return res;
    }
};