/*
 * @Descroption: LeetCode 628. �����������˻�
 * @Author: EmoryHuang
 * @Date: 2021-04-28 15:20:36
 * @����˼·:
 * �������������������������������������ĳ˻����ǽ����
 * �����ڸ������������������С������������ֵ�������������ĳ˻�
 */

class Solution {
   public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};