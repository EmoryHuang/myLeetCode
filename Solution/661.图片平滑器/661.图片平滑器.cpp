/*
 * @Descroption: LeetCode 661. ͼƬƽ����
 * @Author: EmoryHuang
 * @Date: 2022-03-23 09:17:53
 * @Method:
 * ����һ: ģ��
 * ����ÿ���㲢�ж���Χ�ĵ��Ƿ���ڣ�ͳ������Ȼ�����ƽ��ֵ
 *
 * ������: ǰ׺��
 * ʹ�ö�άǰ׺�Ͷ� img ����Ԥ��������ǰ׺��
 * Ȼ�����ÿ���㣬ͬ�����ö�άǰ׺������Χ��ľ�ֵ
 */

class Solution {
   public:
    // ����һ: ģ��
    // vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    //     int m = img.size(), n = img[0].size();
    //     vector<vector<int>> res(m, vector<int>(n, 0));
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             int count = 0;
    //             for (int x = -1; x <= 1; x++) {
    //                 for (int y = -1; y <= 1; y++) {
    //                     if (i + x >= 0 && i + x < m && j + y >= 0 && j + y < n) {
    //                         res[i][j] += img[i + x][j + y];
    //                         count++;
    //                     }
    //                 }
    //             }
    //             res[i][j] /= count;
    //         }
    //     }
    //     return res;
    // }

    // ������: ǰ׺��
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> sum(m + 5, vector<int>(n + 5, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = max(0, i - 1), b = max(0, j - 1);
                int c = min(m - 1, i + 1), d = min(n - 1, j + 1);
                int cnt = (c - a + 1) * (d - b + 1);
                res[i][j] = (sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b]) / cnt;
            }
        }
        return res;
    }
};