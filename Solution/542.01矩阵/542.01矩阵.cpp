/*
 * @Descroption: LeetCode 542. 01 ����
 * @Author: EmoryHuang
 * @Date: 2021-07-30 15:09:25
 * @Method:
 * �� 0 ��λ�ÿ�ʼ���й����������
 * ÿ��������һ�� 1���Ϳ��Եõ� 0 ����� 1 ����̾���
 * Ϊ�˼�㣬������Ԫ�ر�ʶΪ -1 ����δ����
 */

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};
        while (!q.empty()) {
            auto point = q.front();
            int x = point[0], y = point[1];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int _x = x + dx[i];
                int _y = y + dy[i];
                if (_x >= 0 && _x < n && _y >=0 && _y < m && mat[_x][_y] == -1){
                    mat[_x][_y] = mat[x][y] + 1;
                    q.push({_x, _y});
                }
            }
        }
        return mat;
    }
};