/*
 * @Descroption: LeetCode 689. �������ص������������
 * @Author: EmoryHuang
 * @Date: 2021-12-08 19:58:40
 * @Method:
 * ����һ����������
 * ͬʱ�����������ڣ�����¼����
 *
 * ����������̬�滮
 * dp[i][j] ��ʾǰ i ��Ԫ���У�j �������������
 * �����ŷ����а��� num[i], ֻ���� [0, i - k] ��ѡ j - 1 ��������
 * �����ŷ����в����� num[i], dp[i][j] = dp[i - 1][j]
 * ״̬ת�Ʒ��̣�dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + sum[i - k + 1] - sum[i + 1])
 * */

class Solution {
   public:
    // ����һ����������
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum1 = 0, max_sum1 = 0, max_sum1_idx = 0;
        int sum2 = 0, max_sum12 = 0, max_sum12_idx1 = 0, max_sum12_idx2 = 0;
        int sum3 = 0, max_sum123 = 0;
        vector<int> ans;
        for (int i = 2 * k; i < nums.size(); i++) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1) {
                if (sum1 > max_sum1) {
                    max_sum1 = sum1;
                    max_sum1_idx = i - 3 * k + 1;
                }
                if (sum2 + max_sum1 > max_sum12) {
                    max_sum12 = sum2 + max_sum1;
                    max_sum12_idx1 = max_sum1_idx;
                    max_sum12_idx2 = i - 2 * k + 1;
                }
                if (sum3 + max_sum12 > max_sum123) {
                    max_sum123 = sum3 + max_sum12;
                    ans = {max_sum12_idx1, max_sum12_idx2, i - k + 1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }

    // ����������̬�滮
    // vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> sum(n + 1);
    //     for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
    //     // dp[i][j] ��ʾǰ i ��Ԫ���У�j �������������
    //     vector<vector<int>> dp(n + 2, vector<int>(4));
    //     // �����������Ϊ����������������Ҫ�õ�ǰ��������������
    //     for (int i = n - k + 1; i >= 1; i--) {
    //         for (int j = 1; j < 4; j++) {
    //             // �����ŷ����а��� num[i], ֻ���� [0, i - k] ��ѡ j - 1 ��������
    //             // �����ŷ����в����� num[i], dp[i][j] = dp[i - 1][j]
    //             dp[i][j] = max(dp[i + 1][j], dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]);
    //         }
    //     }
    //     vector<int> ans(3);
    //     int i = 1, j = 3, idx = 0;
    //     while (j > 0) {
    //         if (dp[i + 1][j] > dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1])
    //             i++;
    //         else {
    //             ans[idx++] = i - 1;
    //             i += k;
    //             j--;
    //         }
    //     }
    //     return ans;
    // }
};