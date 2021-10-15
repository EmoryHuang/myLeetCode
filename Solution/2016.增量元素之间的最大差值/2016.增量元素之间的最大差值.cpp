/*
 * @Descroption: LeetCode 2016. ����Ԫ��֮�������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-10-15 20:42:24
 * @Method:
 * ���⣬���������ͬʱ�������Ԫ��
 */

class Solution {
   public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, left = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > left) ans = max(ans, nums[i] - left);
            left = min(left, nums[i]);
        }
        return ans;
    }
};