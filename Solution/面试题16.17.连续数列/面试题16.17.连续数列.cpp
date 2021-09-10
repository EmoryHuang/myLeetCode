/*
 * @Descroption: ������ 16.17. ��������
 * @Author: EmoryHuang
 * @Date: 2021-07-28 19:15:42
 * @Method:
 * ��̬�滮
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i - 1] + nums[i], nums[i])
 */

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (int num : nums) {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};