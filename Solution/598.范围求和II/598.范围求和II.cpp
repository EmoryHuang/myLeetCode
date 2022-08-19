/*
 * @Descroption: LeetCode 598. 范围求和 II
 * @Author: EmoryHuang
 * @Date: 2021-09-13 16:21:40
 * @Method:
 * 简单题，由于修改的范围始终是一个从左上角开始的矩阵，
 * 那么只要得到最小的操作行列即可确定最大值所在的矩形
 */

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m, col = n;
        for (auto c : ops) {
            row = min(row, c[0]);
            col = min(col, c[1]);
        }
        return row * col;
    }
};