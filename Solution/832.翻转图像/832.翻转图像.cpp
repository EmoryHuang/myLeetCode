/*
 * @Descroption: LeetCode 832. 翻转图像
 * @Author: EmoryHuang
 * @Date: 2021-06-23 20:00:00
 * @解题思路:
 * 一边左右翻转，一边修改数字
 * 同时修改了左右对称的元素
 */

class Solution {
   public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (n + 1) / 2; j++) {
                int tmp = image[i][j];
                image[i][j] = image[i][n - j - 1] ^ 1;
                image[i][n - j - 1] = tmp ^ 1;
            }
        return image;
    }
};