/*
 * @Descroption: LeetCode 446. �Ȳ����л��� II - ������
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:34:16
 * @Method:
 * ��̬�滮 + ��ϣ��
 * dp[i][d] ��ʾ�� nums[i] ��β�ģ�����Ϊ d �ĵȲ����и���
 * ״̬ת�Ʒ��̣�dp[i][d] += dp[j][d] + 1
 */

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // dp[i] ��ÿ��Ԫ�ؾ�Ϊ��ϣ�� {d: cnt}
        // d ��ʾ�Ȳ����еĲ�ֵ
        // cnt ��ʾ�� nums[i] ��β�ģ�����Ϊ d �ĵȲ����и���
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // ���� nums[i] �� nums[j] ֮��Ĳ�ֵ
                long long d = 1LL * nums[i] - nums[j];
                // �� nums[j] ��β�ģ�����Ϊ d �ĵȲ����и���
                int cnt = dp[j][d];
                ans += cnt;
                // ��Ϊ nums[i] �� nums[j] �Ĳ�ֵҲΪ d������������ 1
                dp[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};