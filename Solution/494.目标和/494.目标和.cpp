/*
 * @Descroption: LeetCode 494. Ŀ���
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:01:36
 * @����˼·:
 * `x` Ϊǰ�����Ϊ`+`�ļ��ϣ�`y` ǰ�����Ϊ`-`�ļ���
 * ������Ŀ����ת��Ϊ `x - y = target`������ `sum(nums) = x + y`
 * ����� `x = (sum(nums) + target) / 2`
 * ������ת��Ϊ��Ŀ�������к�Ϊ `x` ����Ϸ���������01 ��������
 */

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;  // ��������Ԫ��֮��
        if (target > sum || (target + sum) % 2 == 1) return 0;
        int posTarget = (target + sum) / 2;  // �µ�Ŀ��ֵ����Ҫ�������ͣ�
        vector<int> dp(posTarget + 1);
        dp[0] = 1;
        for (int num : nums)
            for (int i = posTarget; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        return dp[posTarget];
    }
};