/*
 * @Descroption: LeetCode 540. 有序数组中的单一元素
 * @Author: EmoryHuang
 * @Date: 2021-07-30 14:36:09
 * @Method:
 * 二分搜索
 * 单一元素只会出现在偶数下标位置
 */

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid % 2 == 1) mid--;
            if (nums[mid] != nums[mid + 1])
                r = mid;
            else
                l = mid + 2;
        }
        return nums[l];
    }
};