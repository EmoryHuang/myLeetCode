/*
 * @Descroption: LeetCode 419. �װ��ϵ�ս��
 * @Author: EmoryHuang
 * @Date: 2021-12-18 08:50:23
 * @Method:
 * ����һ: dfs
 * ����û�����ڵ�ս������˿��Լ�ʹ��dfs, ���鼯�ȷ������
 *
 * ������: һ��ɨ��
 * ���ҽ���ĳ�� X ���ӵġ��Ϸ���&���󷽡���Ϊ X ʱ���ø���Ϊս���׸����ӣ����Խ��м���
 * ͬʱע��߽�����
 * */

class Solution {
   public:
    // ����һ: dfs
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

    // ������: һ��ɨ��
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