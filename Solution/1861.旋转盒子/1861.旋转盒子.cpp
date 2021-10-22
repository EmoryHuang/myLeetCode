/*
 * @Descroption: LeetCode 1861. 旋转盒子
 * @Author: EmoryHuang
 * @Date: 2021-10-22 15:25:27
 * @Method:
 * 模拟
 * 由于石头的水平位置不会发生改变，因此可以遍历每行单独调整
 * 对于每行，从后往前进行遍历，并且更新底部位置，将石头更新到底部
 */

class Solution {
   public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            // bottom 记录底部位置
            int bottom = n;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*')
                    bottom = j;  // 如果是固定障碍物，则更新底部位置
                else if (box[i][j] == '#') {
                    bottom -= 1;
                    swap(box[i][j], box[i][bottom]);
                }
            }
        }
        // 顺时针旋转 90 度
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};