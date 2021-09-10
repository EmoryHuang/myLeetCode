/*
 * @Descroption: LeetCode 922. 按奇偶排序数组 II
 * @Author: EmoryHuang
 * @Date: 2021-04-27 15:06:36
 * @解题思路:
 * 简单解法，设置两个指针，分别指向奇数、偶数的下个位置
 */

class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int odd = 1, even = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[even] = nums[i];
                even += 2;
            } else {
                ans[odd] = nums[i];
                odd += 2;
            }
        }
        return ans;
    }
};