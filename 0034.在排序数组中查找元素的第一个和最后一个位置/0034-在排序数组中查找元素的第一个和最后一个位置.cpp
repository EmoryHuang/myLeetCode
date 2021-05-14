/*
 * @Descroption: LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置
 * @Author: EmoryHuang
 * @Date: 2021-05-10 11:43:36
 * @解题思路: 采用二分的方法，分别寻找左右边界
 * 二分思想很简单，二分细节是魔鬼
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        // 找左边界
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        int start = l;
        // 找右边界
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        int end = l;
        return {start, end};
    }
};