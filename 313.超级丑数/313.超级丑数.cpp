/*
 * @Descroption: LeetCode 313. ��������
 * @Author: EmoryHuang
 * @Date: 2021-08-09 13:46:59
 * @Method:
 * ����һ����С��
 * ÿ��ȡ���Ѷ�Ԫ�� x���� x �Ƕ�����С�ĳ�������
 * �������� primes ���������� p��px Ҳ�ǳ�����������˽��˻������
 * �ظ�����n�μ��ǵ�n����������
 * ����������̬�滮
 * dp[i] ��ʾ��i����������
 * ʹ��m��ָ��ֱ�ָ��dp[i]��primes[i]��������������������
 */

class Solution {
   public:
    // ����һ����С��
    // int nthSuperUglyNumber(int n, vector<int>& primes) {
    //     priority_queue<int, vector<int>, greater<int>> q;
    //     set<int> vis = {1};
    //     int ugly;
    //     q.push(1);
    //     for (int i = 0; i < n; i++) {
    //         ugly = q.top();
    //         q.pop();
    //         for (auto prime : primes) {
    //             int next = ugly * prime;
    //             if (vis.count(next) == 0) {
    //                 vis.insert(next);
    //                 q.push(next);
    //             }
    //         }
    //     }
    //     return ugly;
    // }

    // ����������̬�滮
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        int m = primes.size();
        vector<int> p(m + 1, 1);
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            int minn = INT_MAX;
            for (int j = 0; j < m; j++) minn = min(minn, primes[j] * dp[p[j]]);
            dp[i] = minn;
            for (int j = 0; j < m; j++)
                if (primes[j] * dp[p[j]] == minn) p[j]++;
        }
        return dp[n];
    }
};