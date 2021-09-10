/*
 * @Descroption: LeetCode 526. ����������
 * @Author: EmoryHuang
 * @Date: 2021-08-16 16:29:44
 * @Method:
 * ����һ��״̬ѹ�� + ����
 * ʹ�ö����ƴ���¼���ֵķ���״̬
 * ���ݷ�����������ȱ�����ֱ��������������
 *
 * ��������״̬ѹ�� + dp
 * dp[i][state] ��ʾǰi����״̬Ϊstate�ķ�����
 * ö��i����,��i������״̬state�Լ���i������ֵk
 * ״̬ת�Ʒ��̣�dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
 * ���У�state & (~(1 << (k - 1))) �� state �еĵ� k λ�� 0��Ҳ����δѡȡ k ʱ��״̬
 */

class Solution {
   public:
    // ����һ��״̬ѹ�� + ����
    // int dfs(int n, int i, int vis) {
    //     if (vis == (1 << n) - 1) return 1;
    //     int ans = 0;
    //     for (int ind = 0; ind < n; ind++) {
    //         // �����ѷ��ʹ�����
    //         if ((1 << ind) & vis) continue;
    //         // ���������������
    //         if (i % (ind + 1) == 0 || (ind + 1) % i == 0) {
    //             vis ^= (1 << ind);
    //             ans += dfs(n, i + 1, vis);
    //             vis ^= (1 << ind);
    //         }
    //     }
    //     return ans;
    // }
    // int countArrangement(int n) {
    //     return dfs(n, 1, 0);
    // }

    // ��������״̬ѹ�� + dp
    int countArrangement(int n) {
        int mask = 1 << n;
        // dp[i][state] ��ʾǰi����״̬Ϊstate�ķ�����
        vector<vector<long>> dp(n + 1, vector<long>(mask));
        dp[0][0] = 1;
        // ��������λ��
        for (int i = 1; i <= n; i++) {
            // ��������״̬
            for (int state = 0; state < mask; state++) {
                // ����λ�� i ���� k
                for (int k = 1; k <= n; k++) {
                    // λ�� k ������ 1
                    if ((state >> (k - 1)) & 1 == 0) continue;
                    if (i % k != 0 && k % i != 0) continue;
                    // state & (~(1 << (k - 1))) ��ʾ�� state �еĵ� k λ�� 0
                    // Ҳ����δѡȡ k ʱ��״̬
                    dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))];
                }
            }
        }
        return dp[n][mask - 1];
    }
};