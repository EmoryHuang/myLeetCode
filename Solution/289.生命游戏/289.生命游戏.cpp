/*
 * @Descroption: LeetCode 289. ������Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-10-23 09:23:45
 * @Method:
 * ����һ�� two bits ��״̬������¼ϸ��״̬����һλ��ʾ��һ״̬, �ڶ�λ��ʾ��ǰ״̬
 * 00: dead -> dead
 * 01: livd -> dead
 * 10: dead -> live
 * 11: live -> live
 * �������󣬼�¼ϸ����Χ��ϸ�������������ݶ��ɸı�ϸ��״̬
 * ���������һλ����
 */

class Solution {
   public:
    vector<int> dx = {1, 1, 1, 0, -1, -1, -1, 0}, dy = {1, 0, -1, -1, -1, 0, 1, 1};
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() < 1) return;
        int m = board.size(), n = board[0].size();
        // ����һ�� two bits ��״̬������¼ϸ��״̬
        // ��һλ��ʾ��һ״̬, �ڶ�λ��ʾ��ǰ״̬
        // 00: dead -> dead
        // 01: livd -> dead
        // 10: dead -> live
        // 11: live -> live
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;  // ϸ����Χ��ϸ��������
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) cnt += board[x][y] & 1;
                }
                // ���� 1 & 3����Ӧ״̬ 1
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