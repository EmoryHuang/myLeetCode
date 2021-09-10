/*
 * @Descroption: 剑指 Offer 53 - I. 在排序数组中查找数字 I
 * @Author: EmoryHuang
 * @Date: 2021-07-16 18:35:17
 * @解题思路:
 * 二分法寻找左端点，然后从左端点开始寻找 target
 */

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        int ans = 0;
        while (l < nums.size() && nums[l++] == target) ans++;
        return ans;
    }
};