/*
 * @Descroption: LeetCode 1995. ͳ��������Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-12-29 09:20:35
 * @Method:
 * ����һ: ����
 * ���⣬���� N �ķ�Χ��С������ֱ�ӱ�������
 *
 * ������: ��������
 * ���� dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
 * ״̬ת�Ʒ���
 * �����������Ʒ nums[i-1], ��ô f[i][j][k] = f[i - 1][j][k]
 * ���������Ʒ nums[i-1], ��ô f[i][j][k] = f[i - 1][j - nums[i - 1]][k - 1]
 *
 * �ռ��Ż�: ͨ������������Ϳռ临�Ӷ�
 * */

class Solution {
   public:
    // ����һ: ����
    // int countQuadruplets(vector<int>& nums) {
    //     int n = nums.size(), ans = 0;
    //     for (int a = 0; a < n; a++) {
    //         for (int b = a + 1; b < n; b++) {
    //             for (int c = b + 1; c < n; c++) {
    //                 for (int d = c + 1; d < n; d++) {
    //                     if (nums[a] + nums[b] + nums[c] == nums[d]) ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // ������: ��������
    // int countQuadruplets(vector<int>& nums) {
    //     int n = nums.size(), ans = 0;
    //     // dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(101, vector<int>(4, 0)));
    //     dp[0][0][0] = 1;
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 0; j < 101; j++) {
    //             for (int k = 0; k < 4; k++) {
    //                 dp[i][j][k] += dp[i - 1][j][k];
    //                 // ������ܷ��µ� i ����Ʒ
    //                 if (j - nums[i - 1] >= 0 && k - 1 >= 0) {
    //                     dp[i][j][k] += dp[i - 1][j - nums[i - 1]][k - 1];
    //                 }
    //             }
    //         }
    //     }
    //     for (int i = 3; i <= n; i++) ans += dp[i][nums[i - 1]][3];
    //     return ans;
    // }

    // ������: ��������(�ռ��Ż�)
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
        vector<vector<int>> dp(101, vector<int>(4, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            ans += dp[nums[i - 1]][3];
            for (int j = 100; j >= 0; j--) {
                for (int k = 0; k < 4; k++) {
                    // ������ܷ��µ� i ����Ʒ
                    if (j - nums[i - 1] >= 0 && k - 1 >= 0) {
                        dp[j][k] += dp[j - nums[i - 1]][k - 1];
                    }
                }
            }
        }
        return ans;
    }
};