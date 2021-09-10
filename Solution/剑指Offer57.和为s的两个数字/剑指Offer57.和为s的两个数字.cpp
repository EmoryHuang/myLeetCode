/*
 * @Descroption: 剑指 Offer 57. 和为s的两个数字
 * @Author: EmoryHuang
 * @Date: 2021-08-09 14:31:19
 * @Method:
 * 双指针遍历，寻找和为target的数对
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == target)
                return {nums[l], nums[r]};
            else if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return {};
    }
};