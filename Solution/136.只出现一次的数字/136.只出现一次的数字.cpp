/*
 * @Descroption: LeetCode 136. 只出现一次的数字
 * @Author: EmoryHuang
 * @Date: 2021-03-20 15:08:36
 * @解题思路:
 * 异或运算的应用
 * 交换律：`a ^ b ^ c <=> a ^ c ^ b`
 * 任何数于 0 异或为任何数 `0 ^ n => n`
 * 相同的数异或为 0: `n ^ n => 0`
 */

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};