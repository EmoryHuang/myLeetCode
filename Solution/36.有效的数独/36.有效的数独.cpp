/*
 * @Descroption: LeetCode 36. ��Ч������
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:24:00
 * @����˼·:
 * �ռ任ʱ��
 * ʹ����������ֱ��¼ÿ�У�ÿ�У�ÿ���ÿ�������Ƿ����
 */

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ��������ֱ��¼ÿ�У�ÿ�У�ÿ���ÿ�������Ƿ����
        vector<vector<bool>> row(9, vector<bool>(9));
        vector<vector<bool>> col(9, vector<bool>(9));
        vector<vector<bool>> block(9, vector<bool>(9));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int ind = i / 3 * 3 + j / 3;  // �������
                    if (row[i][num] || col[j][num] || block[ind][num])
                        return false;
                    else {
                        row[i][num] = true;
                        col[j][num] = true;
                        block[ind][num] = true;
                    }
                }
        return true;
    }
};