/*
 * @Descroption: ������ 17.16. ��Ħʦ
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:37:43
 * @����˼·:
 * ��̬�滮����ҽ���
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
 */

class Solution {
   public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};