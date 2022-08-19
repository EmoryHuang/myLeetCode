/*
 * @Descroption: 剑指 Offer II 009. 乘积小于 K 的子数组
 * @Author: EmoryHuang
 * @Date: 2021-08-10 20:19:11
 * @Method:
 * 滑动窗口
 * 遍历数组，若当前乘积未超过 k，则加入窗口，否则移动左窗口
 */

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || k == 1) return 0;
        int l = 0;
        int ans = 0, mul = 1;
        for (int r = 0; r < nums.size(); r++) {
            mul *= nums[r];
            while (mul >= k) mul /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};