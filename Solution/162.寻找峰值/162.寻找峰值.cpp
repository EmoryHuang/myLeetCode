/*
 * @Descroption: LeetCode 162. 寻找峰值
 * @Author: EmoryHuang
 * @Date: 2021-05-10 18:17:36
 * @解题思路: 二分思想
 * 若 mid 恰好位于降序序列或者一个局部下降坡度中，则说明峰值会在本元素的左边。
 * 若 mid 恰好位于升序序列或者一个局部上升坡度中，则说明峰值会在本元素的右边。
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};