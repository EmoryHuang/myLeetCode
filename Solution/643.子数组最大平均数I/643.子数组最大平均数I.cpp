/*
 * @Descroption: LeetCode 643. 子数组最大平均数 I
 * @Author: EmoryHuang
 * @Date: 2021-03-19 15:56:36
 * @解题思路:
 * 一开始直接暴力然而超时，然后又采用滑动窗口的思想，题目还是简单的
 * 先计算前 k 个数之和，然后开始滑动，加上下一个数，减去最前面的数
 */

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, maxn;
        for (int i = 0; i < k; i++) sum += nums[i];  //前 k 个数之和
        maxn = sum;
        for (int i = k; i < len; i++) {  //开始滑动
            sum += nums[i] - nums[i - k];
            maxn = max(maxn, sum);
        }
        return (double)maxn / k;
    }
};