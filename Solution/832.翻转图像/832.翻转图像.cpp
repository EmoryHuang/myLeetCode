/*
 * @Descroption: LeetCode 832. ��תͼ��
 * @Author: EmoryHuang
 * @Date: 2021-06-23 20:00:00
 * @����˼·:
 * һ�����ҷ�ת��һ���޸�����
 * ͬʱ�޸������ҶԳƵ�Ԫ��
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