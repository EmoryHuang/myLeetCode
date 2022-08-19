/*
 * @Descroption: LeetCode 1473. ��ˢ���� III
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:02:36
 * @����˼·: ��ά��̬�滮
 * `dp[i][j][k]`��ʾǰ `i` ��������� `j` ���������� `i-1` �����ӵ���ɫΪ `k` ����С����
 * - �����ǰ����û��ɫ
 *      ����� i-1 ��������� i ��������ɫ��ͬ������γ��µĽ���
 *      ����� i-1 ��������� i ��������ɫ��ͬ���������������
 *      ������Ҫ���� cost ����
 * - �����ǰ��������ɫ
 *      ����� i-1 ��������� i ��������ɫ��ͬ������γ��µĽ���
 *      ����� i-1 ��������� i ��������ɫ��ͬ���������������
 *      ���� cost ����
 * ���ȡ `min(dp[m-1][target][k]),k��[1,n]`
 */

class Solution {
   public:
    int Inf = INT_MAX / 2;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k]��ʾǰi���������j����������i-1�����ӵ���ɫΪk����С����
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1, Inf)));
        // ��ʼ��
        if (houses[0] == 0) {                  // �����һ������û��ɫ
            for (int k = 1; k <= n; k++)       // ����������ɫ
                dp[0][1][k] = cost[0][k - 1];  // ��ʼ��
        } else
            dp[0][1][houses[0]] = 0;   // ��һ�������Ѿ���ɫ�����軨��
        // ѭ���ɼ򻯣�����д�ȽϺ����
        for (int i = 1; i < m; i++) {  // �ӵڶ������ӿ�ʼ
            if (houses[i] == 0) {      // �����ǰ����û��ɫ
                for (int curColor = 1; curColor <= n; curColor++) {      // curColor��[1,n]
                    for (int preColor = 1; preColor <= n; preColor++) {  // prvColor��[1,n]
                        for (int j = 1; j <= target; j++) {
                            if (curColor == preColor)
                                dp[i][j][curColor] =
                                    min(dp[i - 1][j][preColor] + cost[i][curColor - 1],
                                        dp[i][j][curColor]);
                            else
                                dp[i][j][curColor] =
                                    min(dp[i - 1][j - 1][preColor] + cost[i][curColor - 1],
                                        dp[i][j][curColor]);
                        }
                    }
                }
            } else {  //�����ǰ��������ɫ
                int curColor = houses[i];
                for (int preColor = 1; preColor <= n; preColor++) {  // prvColor��[1,n]
                    for (int j = 1; j <= target; j++) {
                        if (curColor == preColor)
                            dp[i][j][curColor] = min(dp[i][j][curColor], dp[i - 1][j][preColor]);
                        else
                            dp[i][j][curColor] =
                                min(dp[i][j][curColor], dp[i - 1][j - 1][preColor]);
                    }
                }
            }
        }
        int ans = Inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m - 1][target][i]);
        }
        return ans == Inf ? -1 : ans;
    }
};