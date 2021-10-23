/*
 * @Descroption: LeetCode 289. 生命游戏
 * @Author: EmoryHuang
 * @Date: 2021-10-23 09:23:45
 * @Method:
 * 利用一个 two bits 的状态机来记录细胞状态，第一位表示下一状态, 第二位表示当前状态
 * 00: dead -> dead
 * 01: livd -> dead
 * 10: dead -> live
 * 11: live -> live
 * 遍历矩阵，记录细胞周围活细胞的数量，根据定律改变细胞状态
 * 最后将数右移一位即可
 */

class Solution {
   public:
    vector<int> dx = {1, 1, 1, 0, -1, -1, -1, 0}, dy = {1, 0, -1, -1, -1, 0, 1, 1};
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() < 1) return;
        int m = board.size(), n = board[0].size();
        // 利用一个 two bits 的状态机来记录细胞状态
        // 第一位表示下一状态, 第二位表示当前状态
        // 00: dead -> dead
        // 01: livd -> dead
        // 10: dead -> live
        // 11: live -> live
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;  // 细胞周围活细胞的数量
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) cnt += board[x][y] & 1;
                }
                // 定律 1 & 3：对应状态 1
                // live -> live
                if (board[i][j] & 1 == 1) {
                    if (cnt == 2 || cnt == 3) board[i][j] = 3;
                } else {
                    // dead -> live
                    if (cnt == 3) board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) board[i][j] >>= 1;
    }
};