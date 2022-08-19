/*
 * @Descroption: LeetCode 153. 寻找旋转排序数组中的最小值
 * @Author: EmoryHuang
 * @Date: 2021-04-08 18:45:36
 * @解题思路: 二分法，关键在于一些细节
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back())
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};