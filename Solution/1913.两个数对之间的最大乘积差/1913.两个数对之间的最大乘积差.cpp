/*
 * @Descroption: LeetCode 1913. ��������֮������˻���
 * @Author: EmoryHuang
 * @Date: 2021-09-23 19:10:40
 * @Method:
 * ���⣬����֮��ȡͷβ4��Ԫ��
 */

class Solution {
   public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};