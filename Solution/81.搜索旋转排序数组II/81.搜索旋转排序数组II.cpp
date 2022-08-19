/*
 * @Descroption: LeetCode 81. 搜索旋转排序数组 II
 * @Author: EmoryHuang
 * @Date: 2021-04-07 18:20:36
 * @解题思路: 基本思路与[搜索旋转排序数组]相同，，但数组中可能有重复元素
 * 虽然说直接遍历也可以通过，但还是尝试了二分法，由于是旋转的数组，因此还需要判断 mid 的位置
 */

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while (left < right && nums[left] == nums[left + 1]) left++;     // 跳过重复元素
            while (left < right && nums[right] == nums[right - 1]) right--;  // 跳过重复元素
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])  // target落在左半边
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right])  // target落在右半边
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};