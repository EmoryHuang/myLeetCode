/*
 * @Descroption: LeetCode 300. �����������
 * @Author: EmoryHuang
 * @Date: 2021-03-25 14:28:36
 * @����˼·:
 * ��̬�滮���⣬`dp[i]` ��ʾ�� `nums[i]` ��β������������еĳ���
 * λ�� i ������������е��� j �� 0 �� i-1 ����λ�õ������������ + 1 �����ֵ��
 * ת�Ʒ��̣� `dp[i] = max(dp[i], dp[j] + 1)`
 */

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);  // ��ʼΪ1
        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {  //Ѱ�� i ֮ǰС�� nums[i] ����
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};