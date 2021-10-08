/*
 * @Descroption: LeetCode 2008. ���⳵�����ӯ��
 * @Author: EmoryHuang
 * @Date: 2021-10-08 20:38:49
 * @Method:
 * ����һ����̬�滮
 * dp[i] ��ʾ�� i ��β��λ���ܵõ����������
 * �����ؿͣ����� dp[i] = dp[i - 1]
 * ���ؿͣ���ѡ��ǰλ���ܻ�õ�������� dp[i] = max(dp[i], dp[start] + profit)
 *
 * ����������̬�滮 + ����
 * ״̬ת�Ʒ���: dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
 * ʹ�ö��ֲ��ң�Ѱ�Ҿ��뵱ǰ�յ���������λ��
 */

class Solution {
   public:
    // ����һ����̬�滮
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // dp[i] ��ʾ�� i ��β��λ���ܵõ����������
        vector<long long> dp(n + 1);
        vector<vector<pair<int, int>>> hash(n + 1);
        for (auto r : rides) hash[r[1]].push_back({r[0], r[1] - r[0] + r[2]});
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];  // ���ؿ�
            for (auto [start, w] : hash[i]) dp[i] = max(dp[i], dp[start] + w);
        }
        return dp[n];
    }
};