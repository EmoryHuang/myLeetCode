/*
 * @Descroption: ��ָ Offer II 102. �Ӽ���Ŀ��ֵ
 * @Author: EmoryHuang
 * @Date: 2021-11-11 19:35:58
 * @Method:
 * ��̬�滮
 * x Ϊǰ�����Ϊ + �ļ��ϣ�y ǰ�����Ϊ - �ļ���
 * ������Ŀ����ת��Ϊ x - y = target������ sum(nums) = x + y
 * ����� x = (sum(nums) + target) / 2
 * ������ת��Ϊ��Ŀ�������к�Ϊ x ����Ϸ���������01 ��������
 * dp[i][j] ��ʾǰ i ��������Ϊ j �ķ�����
 * ״̬ת�Ʒ���
 * dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
 */


class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum + target) % 2) return 0;
        // ��Ҫ������֮��
        int pos = (sum + target) / 2;
        vector<int> dp(pos + 1);
        dp[0] = 1;
        for (int num : nums)
            // �������
            for (int i = pos; i >= num; i--) dp[i] += dp[i - num];
        return dp[pos];
    }
};