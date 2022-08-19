/*
 * @Descroption: LeetCode 54. 螺旋矩阵
 * @Author: EmoryHuang
 * @Date: 2021-03-23 13:16:36
 * @解题思路:
 * 模拟螺旋矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限，顺时针旋转，进入下一个方向
 */

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        if (m == 0 || n == 0) return ans;
        int top = 0, bottom = m - 1, right = n - 1, left = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) ans.push_back(matrix[top][i]);    //从左到右
            top++;                                                                //顶部往下
            for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);  //从上到下
            right--;                                                              //右部往左
            for (int i = right; i >= left && top <= bottom; i--)
                ans.push_back(matrix[bottom][i]);  //从右到左
            bottom--;                              //底部往上
            for (int i = bottom; i >= top && left <= right; i--)
                ans.push_back(matrix[i][left]);  //从下到上
            left++;                              //左部往右
        }
        return ans;
    }
};