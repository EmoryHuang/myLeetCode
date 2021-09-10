/*
 * @Descroption: LeetCode 119. ������� II
 * @Author: EmoryHuang
 * @Date: 2021-04-20 15:30:36
 * @����˼·: ��[108. �������]���ƣ�����������ǵĹ��ɼ���
 */

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> yh(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {  //�߽�
            yh[i].resize(i + 1);
            yh[i][0] = 1;
            yh[i][i] = 1;
            for (int j = 1; j < i; j++) {
                yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
            }
        }
        return yh[rowIndex];
    }
};