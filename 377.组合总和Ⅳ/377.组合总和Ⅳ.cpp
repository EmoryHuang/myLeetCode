/*
 * @Descroption: LeetCode 377. ����ܺ� ��
 * @Author: EmoryHuang
 * @Date: 2021-04-24 13:38:36
 * @����˼·:
 * `dp[i]` ���������Ϊ `i` ʱ,ʹ�� `nums` �е�������ɵ�������ĸ���
 * ��`1 �� i �� target`ʱ���������һ�����У����е�Ԫ��֮�͵���`i`��
 * ������е����һ��Ԫ��һ�������� `nums` �е�һ��Ԫ�ء�
 * ��������е����һ��Ԫ���� `num`����һ����`num �� i`������Ԫ��֮�͵��� `i-num` ��ÿһ�����У�
 * �������� `num` ֮�󼴿ɵõ���Ԫ��֮�͵���`i`������
 */

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int num : nums)
                // �� target ֮ǰ��������������ܳ��� INT_MAX
                if (i >= num && dp[i - num] < INT_MAX) {
                    dp[i] += dp[i - num];
                }
        return dp[target];
    }
};