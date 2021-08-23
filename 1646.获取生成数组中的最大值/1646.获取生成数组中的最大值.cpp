/*
 * @Descroption: LeetCode 1646. 获取生成数组中的最大值
 * @Author: EmoryHuang
 * @Date: 2021-08-23 11:02:39
 * @Method:
 * 简单题，遍历数组，按题目给定的方式赋值，同时记录最大值
 */

class Solution {
   public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        vector<int> nums(n + 1);
        nums[1] = 1;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                nums[i] = nums[i / 2];
            else
                nums[i] = nums[i / 2] + nums[(i + 1) / 2];
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};