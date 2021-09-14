/*
 * @Descroption: LeetCode 1605. �����к��еĺ�����о���
 * @Author: EmoryHuang
 * @Date: 2021-09-14 16:11:05
 * @Method:
 * ̰��
 * ʹ�� rowCur, colCur �ֱ��¼��ǰÿ��ÿ�еĺ�
 * ����ÿ��λ�ã�ȡ���е�ǰ�������������Ľ�Сֵ
 */

class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        // rowCur, colCur �ֱ��¼��ǰÿ��ÿ�еĺ�
        vector<int> rowCur(row), colCur(col);
        vector<vector<int>> ans(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // ȡ���е�ǰ�������������Ľ�Сֵ
                int num = min(rowSum[i] - rowCur[i], colSum[j] - colCur[j]);
                ans[i][j] = num;
                rowCur[i] += num;
                colCur[j] += num;
            }
        }
        return ans;
    }
};