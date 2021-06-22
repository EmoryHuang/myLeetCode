/*
 * @Descroption: LeetCode 1365. 有多少小于当前数字的数字
 * @Author: EmoryHuang
 * @Date: 2021-06-22 19:52:00
 * @解题思路:
 * cnt[i] 表示数字 i 出现的次数。
 * 那么对于数字 i 而言，小于它的数目就为 cnt[0...i-1] 的总和
 */

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101);
        for (int num : nums) cnt[num]++;
        for (int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) ans.push_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
        return ans;
    }
};