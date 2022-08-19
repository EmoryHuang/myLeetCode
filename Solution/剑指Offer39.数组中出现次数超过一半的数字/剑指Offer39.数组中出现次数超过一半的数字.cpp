/*
 * @Descroption: 剑指 Offer 39. 数组中出现次数超过一半的数字
 * @Author: EmoryHuang
 * @Date: 2021-07-03 15:28:53
 * @解题思路:
 * 方法一：排序后取中位数
 * 由于数字的出现次数超过一半，因此中位数一定是这个数
 * 方法二：哈希表
 */

class Solution {
   public:
    // 方法一：排序后取中位数
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // 方法二：哈希表
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> mp;
    //     for (int num : nums)
    //         if (mp[num]++ > nums.size()) return num;
    //     return 0;
    // }
};