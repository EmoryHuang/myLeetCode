/*
 * @Descroption: LeetCode 33. 搜索旋转排序数组
 * @Author: EmoryHuang
 * @Date: 2021-03-23 12:16:36
 * @解题思路: 刚开始不是很懂题目想表达什么，直接暴力来一遍
 * 方法二是二分搜索，由于是旋转的数组，因此还需要判断 mid 的位置
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // 方法一：不管三七二十一
    // int search(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.size(); i++)
    //         if (nums[i] == target) return i;
    //     return -1;
    // }

    // 方法二：二分
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        // 寻找旋转数组的最小值
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back())
                right = mid;
            else
                left = mid + 1;
        }
        // 判断 target 所在区域
        if (target <= nums.back())
            right = nums.size() - 1;
        else {
            left = 0;
            right--;
        }
        // 寻找 target
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[left] != target) return -1;
        return left;
    }
};