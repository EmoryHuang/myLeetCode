/*
 * @Descroption: LeetCode 62. ��ͬ·��
 * @Author: EmoryHuang
 * @Date: 2021-03-21 20:30:36
 * @����˼·:
 * �����뵽���Ƕ�̬�滮��ͦ�����뵽�ģ���i��j������ͨ����i-1��j���ͣ�i��j-1��������Եõ���
 * mp[i][j] = mp[i - 1][j] + mp[i][j - 1]
 *
 * �ڶ��������������
 * �����Ͻǵ����½ǵĹ����У�������Ҫ�ƶ� m + n - 2 �Σ�
 * ������ m - 1 �������ƶ��� n - 1 �������ƶ���
 * ���·�����������͵��ڴ� m + n - 2 ���ƶ���ѡ�� m - 1 �������ƶ��ķ�������������� C(m+n-2,m-1)
 */

class Solution {
   public:
    // ����һ����̬�滮
    int uniquePaths(int m, int n) {
        vector<vector<int>> mp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    mp[i][j] = 1;
                else
                    mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
            }
        }
        return mp[m - 1][n - 1];
    }

    // �������������
    // int uniquePaths(int m, int n) {
    //     long long ans = 1;
    //     for (int x = n, y = 1; y < m; ++x, ++y) {
    //         ans = ans * x / y;
    //     }
    //     return ans;
    // }
};