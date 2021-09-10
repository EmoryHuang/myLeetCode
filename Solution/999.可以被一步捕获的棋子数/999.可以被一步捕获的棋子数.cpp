/*
 * @Descroption: LeetCode 999. ���Ա�һ�������������
 * @Author: EmoryHuang
 * @Date: 2021-08-19 19:22:09
 * @Method:
 * ���⣬���ҵ��׳���Ȼ����4���������
 */

class Solution {
   public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    for (int k = 0; k < 4; k++) {
                        int x = i, y = j;
                        while (true) {
                            x += dx[k];
                            y += dy[k];
                            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') break;
                            if (board[x][y] == 'p') {
                                ans++;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
};