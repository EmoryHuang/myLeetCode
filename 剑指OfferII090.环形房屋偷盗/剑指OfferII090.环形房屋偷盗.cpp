/*
 * @Descroption: ��ָ Offer II 090. ���η���͵��
 * @Author: EmoryHuang
 * @Date: 2021-08-09 20:14:44
 * @Method:
 * ��̬�滮
 * ��һ�������һ������ͬʱ����������һ����ʱ�����һ�������ɲ�������һ�����ͬ��
 * dp[i] ��ʾ����i������Ϊֹ��͵���������
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        int ans = 0;
        // ��͵��һ��
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        ans = dp[n - 1];
        // ��͵���һ��
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return max(ans, dp[n - 2]);
    }
};