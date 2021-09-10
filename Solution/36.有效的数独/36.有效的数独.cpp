/*
 * @Descroption: LeetCode 36. 有效的数独
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:24:00
 * @解题思路:
 * 空间换时间
 * 使用三个数组分别记录每行，每列，每块的每个数字是否出现
 */

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 三个数组分别记录每行，每列，每块的每个数字是否出现
        vector<vector<bool>> row(9, vector<bool>(9));
        vector<vector<bool>> col(9, vector<bool>(9));
        vector<vector<bool>> block(9, vector<bool>(9));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int ind = i / 3 * 3 + j / 3;  // 块内序号
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