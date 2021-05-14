/*
 * @Descroption: LeetCode 264. ���� II
 * @Author: EmoryHuang
 * @Date: 2021-04-11 17:04:36
 * @����˼·:
 * ͨ�������жϳ����ᳬʱ
 *
 * ʹ�ö�̬�滮��������������ָ��`p2`��`p3`��`p5`����`dp[0]=1`
 * `p2`��`p3`��`p5`�ֱ�ָ��`dp[i]`�� 2 ����3 ����5 ������
 * ����������������`dp[n-1]`��Ϊ����
 */

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) p2++;  // ����
            if (dp[i] == num3) p3++;
            if (dp[i] == num5) p5++;
        }
        return dp[n - 1];
    }
};