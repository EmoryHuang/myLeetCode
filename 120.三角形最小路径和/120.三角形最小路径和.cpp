/*
 * @Descroption: LeetCode 120. ��������С·����
 * @Author: EmoryHuang
 * @Date: 2021-07-29 15:06:01
 * @Method:
 * ��̬�滮
 * dp[i][j] ��ʾ��i��j�е���С·����
 * ״̬ת�Ʒ��̣�dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
 */

class Solution {
   public:
    // ���䶯̬�滮
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     if (n == 1) return triangle[0][0];
    //     vector<vector<int>> dp(n, vector<int>(n));
    //     for (int i = 0; i < triangle.back().size(); i++) dp[n - 1][i] = triangle.back()[i];
    //     for (int i = n - 2; i >= 0; i--) {
    //         for (int j = 0; j <= i; j++) {
    //             dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // ԭ���޸�
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     for (int i = n - 1; i > 0; i--)
    //         for (int j = 0; j < i; j++) {
    //             triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
    //         }
    //     return triangle[0][0];
    // }

    // һά�ռ�
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];
        vector<int> dp = triangle.back();
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        return dp[0];
    }
};