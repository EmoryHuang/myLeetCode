/*
 * @Descroption: LeetCode 189. 旋转数组
 * @Author: EmoryHuang
 * @Date: 2021-03-24 19:32:36
 * @解题思路: 最开始试了 O(kn)的暴力法，发现超时，通过 reverse()的效率还是挺高的
 */

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums.begin(), nums.end());        // 翻转整个数组
        reverse(nums.begin(), nums.begin() + k);  // 翻转前k个
        reverse(nums.begin() + k, nums.end());    // 翻转后k个
    }
};