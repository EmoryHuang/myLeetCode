/*
 * @Descroption: LeetCode 1269. ͣ��ԭ�صķ�����
 * @Author: EmoryHuang
 * @Date: 2021-05-13 14:20:36
 * @����˼·: ��̬�滮
 * `dp[j]` ��ʾ���±� `j` ���ķ�������`next`Ϊ��һ��������� dp
 * ������`next[j] = dp[j]`
 * ���ң�`next[j] = dp[j - 1] + next[j]`
 * ����`next[j] = dp[j + 1] + next[j]`
 */

class Solution {
   public:
    const int M = 1000000007;
    int numWays(int steps, int arrLen) {
        int n = min(arrLen - 1, steps);
        vector<int> dp(n + 1);  // dp[j]��ʾ���±�j���ķ�����
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> next(n + 1);  //��һ���������dp
            for (int j = 0; j <= n; j++) {
                next[j] = dp[j];                          // ����
                if (j - 1 >= 0) {                         // �߽�
                    next[j] = (dp[j - 1] + next[j]) % M;  // ����
                }
                if (j + 1 <= n) {                         // �߽�
                    next[j] = (dp[j + 1] + next[j]) % M;  // ����
                }
            }
            dp = next;
        }
        return dp[0];
    }
};