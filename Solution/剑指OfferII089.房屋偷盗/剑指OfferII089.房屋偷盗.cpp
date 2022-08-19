/*
 * @Descroption: ��ָ Offer II 089. ����͵��
 * @Author: EmoryHuang
 * @Date: 2021-08-09 19:51:14
 * @Method:
 * ��̬�滮
 * dp[i] ��ʾ����i������Ϊֹ��͵���������
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[n - 1];
    }
};