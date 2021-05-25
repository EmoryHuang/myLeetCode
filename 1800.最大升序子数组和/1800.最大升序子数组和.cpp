/*
 * @Descroption: LeetCode 1800. ��������������
 * @Author: EmoryHuang
 * @Date: 2021-05-25 12:49:11
 * @����˼·:
 * �������飬��nums[i - 1] < nums[i]���ۼ�sum�����������ۼ�
 */

class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int sum = nums[0], ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
                ans = max(ans, sum);
            } else
                sum = nums[i];
        }
        return ans;
    }
};