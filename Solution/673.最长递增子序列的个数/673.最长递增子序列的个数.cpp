/*
 * @Descroption: LeetCode 673. ����������еĸ���
 * @Author: EmoryHuang
 * @Date: 2021-09-20 19:12:50
 * @Method:
 * ��̬�滮
 * �ڴ�ͳ����������еĻ��������ӱ���
 * dp[i] ��ʾ�� nums[i] ��β������������еĳ���
 * cnt[i] ��ʾ�� nums[i] ��β������������еĸ���
 * �� dp[i] == dp[j] + 1 �У�cnt[i] += cnt[j]
 */

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] ��ʾ�� nums[i] ��β������������еĳ���
        // cnt[i] ��ʾ�� nums[i] ��β������������еĸ���
        vector<int> dp(n), cnt(n);
        int len = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = cnt[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1)
                        cnt[i] += cnt[j];  // �ۻ�
                }
            }
            len = max(len, dp[i]);  // ��¼������г���
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == len) ans += cnt[i];
        return ans;
    }
};