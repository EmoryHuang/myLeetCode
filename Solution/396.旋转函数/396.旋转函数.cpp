/*
 * @Descroption: LeetCode 396. 旋转函数
 * @Author: EmoryHuang
 * @Date: 2022-04-22 08:53:42
 * @Method:
 * 迭代
 * 可以通过式子找到规律
 * F(i) = F(i - 1) + sum(nums) - n * num[n - i]
 */

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), f = 0;
        int sumnum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) f += i * nums[i];
        int maxf = f;
        for (int i = n - 1; i > 0; i--) {
            f = f + sumnum - n * nums[i];
            maxf = max(maxf, f);
        }
        return maxf;
    }
};