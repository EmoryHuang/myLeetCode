/*
 * @Descroption: LeetCode 154. 寻找旋转排序数组中的最小值 II
 * @Author: EmoryHuang
 * @Date: 2021-04-08 19:01:36
 * @解题思路: 与[153. 寻找旋转排序数组中的最小值]相同，二分法，关键在于处理重复值
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
            else  // nums[mid]等于nums[right]时
                right--;
        }
        return nums[left];
    }
};