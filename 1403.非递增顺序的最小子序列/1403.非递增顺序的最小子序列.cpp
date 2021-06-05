/*
 * @Descroption: LeetCode 1403. 非递增顺序的最小子序列
 * @Author: EmoryHuang
 * @Date: 2021-06-05 14:59:00
 * @解题思路:
 * 贪心思想，首先将 nums 进行排序
 * 然后从大到小选择元素，若该子序列中的元素之和大于剩余元素，则找到
 */

class Solution {
   public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, subsum = 0;
        for (int num : nums) sum += num;
        vector<int> sub;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sub.push_back(nums[i]);
            subsum += nums[i];
            if (subsum > sum - subsum) return sub;
        }
        return sub;
    }
};