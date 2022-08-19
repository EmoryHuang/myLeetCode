/*
 * @Descroption: LeetCode 1155. �����ӵ�N�ַ���
 * @Author: EmoryHuang
 * @Date: 2021-05-26 17:01:17
 * @����˼·:
 * ��̬�滮�����鱳������
 * dp[i][j]��ʾǰi�����ӵõ��ܺ�Ϊj����������Ŀ
 * ״̬ת�Ʒ��̣�dp[i][j] = dp[i][j] + dp[i - 1][j - k], k = 1 ... f
 * ö�ٴ���Ϊ���Ӹ������ܺͣ�ÿ�ε÷���
 *
 * ��Ȼ���뱳���������ƣ�Ҳ���Խ���ά�ռ��Ż�Ϊһλ�ռ�
 * dp[j]��ʾ�õ��ܺ�Ϊj����������Ŀ
 *
 * �����йؽ����������ķ������Բο���[�����Ž�ѧϰ�ʼ�](https://emoryhuang.github.io/blog/4096131275.html)
 */

class Solution {
   public:
    // int numRollsToTarget(int d, int f, int target) {
    //     // dp[i][j]��ʾǰi�����ӵõ��ܺ�Ϊj����������Ŀ
    //     vector<vector<int>> dp(d + 1, vector<int>(target + 1));
    //     dp[0][0] = 1;
    //     for (int i = 1; i <= d; i++)
    //         for (int j = i; j <= target; j++)
    //             for (int k = 1; k <= f; k++)
    //                 if (j >= k)
    //                     dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
    //     return dp[d][target];
    // }

    // �ռ��Ż�
    int numRollsToTarget(int d, int f, int target) {
        // dp[j]��ʾ�õ��ܺ�Ϊj����������Ŀ
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= d; i++)
            for (int j = target; j >= 0; j--) {
                dp[j] = 0;  // ��ʼ��Ϊ0
                for (int k = 1; k <= f; k++)
                    if (j >= k) dp[j] = (dp[j] + dp[j - k]) % 1000000007;
            }
        return dp[target];
    }
};