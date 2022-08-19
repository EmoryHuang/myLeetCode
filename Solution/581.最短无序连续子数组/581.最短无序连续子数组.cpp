/*
 * @Descroption: LeetCode 581. 最短无序连续子数组
 * @Author: EmoryHuang
 * @Date: 2021-08-03 11:09:55
 * @Method:
 * 方法一：排序
 * 将原数组排序之后，比较前半部分和后半部分有序部分的长度
 * 方法二：双指针
 * 我们可以通过寻找无序连续子数组中的最大值和最小值确定左右边界
 */

class Solution {
   public:
    // 方法一：排序
    // int findUnsortedSubarray(vector<int>& nums) {
    //     if (is_sorted(nums.begin(), nums.end())) return 0;
    //     int n = nums.size();
    //     vector<int> copy = nums;
    //     sort(nums.begin(), nums.end());
    //     int l = 0, r = n - 1;
    //     while (copy[l] == nums[l]) l++;
    //     while (copy[r] == nums[r]) r--;
    //     return r - l + 1;
    // }

    // 方法二：双指针
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -1;
        int minn = INT_MAX, maxn = INT_MIN;
        for (int i = 0; i < n; i++) {
            // 寻找无序子数组的右边界
            if (nums[i] >= maxn)
                maxn = nums[i];  // 升序，更新maxn
            else
                r = i;  // 降序，更新边界
            // 寻找无序子数组的左边界
            if (nums[n - i - 1] <= minn)
                minn = nums[n - i - 1];
            else
                l = n - i - 1;
        }
        if (l == -1) return 0;
        return r - l + 1;
    }
};