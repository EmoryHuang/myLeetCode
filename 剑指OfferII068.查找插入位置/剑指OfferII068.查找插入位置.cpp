/*
 * @Descroption: 剑指 Offer II 068. 查找插入位置
 * @Author: EmoryHuang
 * @Date: 2021-08-06 18:35:23
 * @Method:
 * 二分法寻找左端点
 */

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        // 二分法寻找左端点
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l] >= target ? l : nums.size();
    }
};