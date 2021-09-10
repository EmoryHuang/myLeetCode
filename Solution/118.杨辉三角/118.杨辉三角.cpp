/*
 * @Descroption: LeetCode 118. �������
 * @Author: EmoryHuang
 * @Date: 2021-04-20 15:26:36
 * @����˼·: ����������ǵĹ��ɼ���
 */

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yh(numRows);
        for (int i = 0; i < numRows; i++) {  //�߽�
            yh[i].resize(i + 1);
            yh[i][0] = 1;
            yh[i][i] = 1;
            for (int j = 1; j < i; j++) {
                yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
            }
        }
        return yh;
    }
};