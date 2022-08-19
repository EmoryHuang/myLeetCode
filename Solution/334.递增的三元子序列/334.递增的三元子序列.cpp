/*
 * @Descroption: LeetCode 334. 递增的三元子序列
 * @Author: EmoryHuang
 * @Date: 2021-07-27 19:26:17
 * @Method:
 * 最长递增子序列问题
 * 维护最小值和中间值，若找到比中间值更大的元素，则找到了三元子序列
 */

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, mid = INT_MAX;
        for (int num : nums) {
            if (min >= num)
                min = num;
            else if (mid >= num)
                mid = num;
            else
                return true;
        }
        return false;
    }
};