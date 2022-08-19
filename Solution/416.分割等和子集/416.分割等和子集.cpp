/*
 * @Descroption: LeetCode 234. ��������
 * @Author: EmoryHuang
 * @Date: 2021-05-23 16:29:11
 * @����˼·:
 * 01��������
 * dp[i]��ʾ�ܷ�ָ�Ϊ��Ϊi���Ӽ�
 * ״̬ת�Ʒ��� dp[j] = dp[j] || dp[j - num];
 */

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        vector<bool> dp(sum / 2 + 1);
        dp[0] = true;
        for (int num : nums) {
            for (int j = sum / 2; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[sum / 2];
    }
};