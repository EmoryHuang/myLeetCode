/*
 * @Descroption: LeetCode 198. ��ҽ���
 * @Author: EmoryHuang
 * @Date: 2021-04-15 19:28:36
 * @����˼·: ��̬�滮����
 * `dp[i]`��ʾ����`i`����͵�����ֵ��
 * ״̬ת�Ʒ��� `dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])`
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[len - 1];
    }
};