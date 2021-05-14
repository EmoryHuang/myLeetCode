/*
 * @Descroption: LeetCode 35. 搜索插入位置
 * @Author: EmoryHuang
 * @Date: 2021-03-22 17:02:36
 * @解题思路: 简单题，思路没什么好说的，直接遍历搜索也可以，二分查找也可以
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // 方法一：遍历查找
    // int searchInsert(vector<int>& nums, int target) {
    //     for (int i = 0; i < nums.length; i++) {
    //         if (nums[i] >= target) {
    //             return i;
    //         }
    //     }
    //     return nums.length;
    // }

    // 方法二：二分
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums.back() < target) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};