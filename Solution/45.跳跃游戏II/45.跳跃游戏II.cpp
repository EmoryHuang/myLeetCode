/*
 * @Descroption: LeetCode 45. ��Ծ��Ϸ II
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:43:00
 * @����˼·:
 * ��̬�滮
 * �������飬ÿ�α��������ܹ������λ�õ���С��Ծ����
 * dp[i]��ʾ����λ��i����С��Ծ����
 * ���ܹ���λ��j����λ��i����ôdp[i] = min(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i)               // �ܹ���λ��j����λ��i
                    dp[i] = min(dp[i], dp[j] + 1);  // ������С��Ծ����
            }
        return dp[n - 1];
    }
};