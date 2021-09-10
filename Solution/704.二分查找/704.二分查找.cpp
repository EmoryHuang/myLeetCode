/*
 * @Descroption: LeetCode 704. 二分查找
 * @Author: EmoryHuang
 * @Date: 2021-03-27 10:36:36
 * @解题思路:
 * 基础题，二分查找
 */

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};