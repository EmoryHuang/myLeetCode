/*
 * @Descroption: LeetCode 561. 数组拆分 I
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:29:56
 * @解题思路:
 * 首先对数组进行排序
 * 然后将奇数位的数字相加即可
 */

class Solution {
   public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) ans += nums[i];
        return ans;
    }
};