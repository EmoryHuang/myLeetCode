/*
 * @Descroption: LeetCode 59. 螺旋矩阵 II
 * @Author: EmoryHuang
 * @Date: 2021-03-23 16:06:36
 * @解题思路:
 * 与[螺旋矩阵]的方法基本相同，模拟螺旋矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限，顺时针旋转，进入下一个方向
 */

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = n - 1, right = n - 1, left = 0;
        int num = 1;
        while (num <= n * n) {
            for (int i = left; i <= right; i++) ans[top][i] = num++;     //从左到右
            top++;                                                       //顶部往下
            for (int i = top; i <= bottom; i++) ans[i][right] = num++;   //从上到下
            right--;                                                     //右部往左
            for (int i = right; i >= left; i--) ans[bottom][i] = num++;  //从右到左
            bottom--;                                                    //底部往上
            for (int i = bottom; i >= top; i--) ans[i][left] = num++;    //从下到上
            left++;                                                      //左部往右
        }
        return ans;
    }
};