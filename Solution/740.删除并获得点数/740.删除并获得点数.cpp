/*
 * @Descroption: LeetCode 740. ɾ������õ���
 * @Author: EmoryHuang
 * @Date: 2021-05-05 20:24:36
 * @����˼·:
 * ��Ԫ�� `x` �������г��ֵĴ���Ϊ `c`�������� `count` ��¼���� `nums` ��Ԫ�س��ֵĴ�����
 * ��ѡ���� `x`������Ի�ȡ `sum[x]` �ĵ��������޷���ѡ�� `x-1` �� `x+1`��
 * ���ת������ [198. ��ҽ���]
 * ʹ�ö�̬�滮�ķ�����״̬ת�Ʒ���Ϊ
 * `dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * (i))`
 * `dp [0] = 0,dp[1] = count[1]`
 */

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());  //�����е����Ԫ��
        vector<int> dp(m + 1), count(m + 1);
        for (int num : nums) count[num]++;  //��¼ÿ�����ֳ��ֵĴ���
        dp[1] = count[1];
        for (int i = 2; i <= m; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * (i));
        }
        return dp[m];
    }
};