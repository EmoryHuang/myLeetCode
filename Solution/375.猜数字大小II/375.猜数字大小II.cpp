/*
 * @Descroption: LeetCode 375. �����ִ�С II
 * @Author: EmoryHuang
 * @Date: 2021-11-12 19:27:40
 * @Method:
 * ����һ: dfs
 * �ݹ�õ���ǰ������ѡ�����ֵ���������õĽ��
 *
 * ������: ��̬�滮
 * dp[i][j] ��ʾ������ [i, j] ��ѡ�����С�ɱ�
 * cur = max(dp[l][i - 1], dp[i + 1][r]) + i
 */

class Solution {
   public:
    // ����һ: dfs
    // vector<vector<int>> cache;
    // int dfs(int l, int r) {
    //     if (l >= r) return 0;
    //     if (cache[l][r]) return cache[l][r];
    //     int ans = INT_MAX;
    //     // ����ѡ�������
    //     for (int i = l; i <= r; i++) {
    //         int cur = max(dfs(l, i - 1), dfs(i + 1, r)) + i;
    //         ans = min(ans, cur);
    //     }
    //     cache[l][r] = ans;
    //     return ans;
    // }
    // int getMoneyAmount(int n) {
    //     cache.resize(201, vector<int>(201));
    //     return dfs(1, n);
    // }

    // ������: ��̬�滮
    int getMoneyAmount(int n) {
        // dp[i][j] ��ʾ������ [i, j] ��ѡ�����С�ɱ�
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // ����ѡ�񳤶�
        for (int len = 2; len <= n; len++) {
            // ������˵�
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = 0x3f3f3f3f;
                for (int i = l; i <= r; i++) {
                    int cur = max(dp[l][i - 1], dp[i + 1][r]) + i;
                    dp[l][r] = min(dp[l][r], cur);
                }
            }
        }
        return dp[1][n];
    }
};