/*
 * @Descroption: LeetCode 840. 矩阵中的幻方
 * @Author: EmoryHuang
 * @Date: 2021-03-24 19:19:36
 * @解题思路:
 * 有一定的剪枝，中心元素一定是 5 ，和一定是 15
 */

class Solution {
   public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;
        int c = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int flag = 0;
                if (grid[i + 1][j + 1] == 5 && grid[i][j] != grid[i][j + 1]) {
                    for (int p = 0; p < 3; p++) {
                        for (int q = 0; q < 3; q++) {
                            if (grid[i + p][j + q] > 0 && grid[i + p][j + q] < 10) {
                                flag++;
                            }
                        }
                    }
                }
                if (flag == 9 && grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15 &&
                    grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15 &&
                    grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15 &&
                    grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15 &&
                    grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15 &&
                    grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15 &&
                    grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15 &&
                    grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] == 15)
                    c++;
            }
        }
        return c;
    }
};