/*
 * @Descroption: 剑指 Offer 53 - II. 0～n-1中缺失的数字
 * @Author: EmoryHuang
 * @Date: 2021-07-23 18:47:14
 * @解题思路:
 * 二分法寻找左端点
 */

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};