/*
 * @Descroption: LeetCode 498. �Խ��߱���
 * @Author: EmoryHuang
 * @Date: 2021-08-12 19:42:58
 * @Method:
 * ģ��
 * �жϵ�ǰ�Խ��ߵĲ�����Ȼ������µ����ϻ��ߴ����ϵ�����
 */

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        if (mat.size() == 0) return ans;
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            ans.push_back(mat[row][col]);
            if ((row + col) % 2 == 0) {
                if (col == n - 1)  // ���һ��
                    row += 1;
                else if (row == 0)  // ��һ��
                    col += 1;
                else  // ���µ�����
                    row--, col++;
            } else {
                if (row == m - 1)  // ���һ��
                    col += 1;
                else if (col == 0)  // ��һ��
                    row += 1;
                else  // ���µ�����
                    row++, col--;
            }
        }
        return ans;
    }
};