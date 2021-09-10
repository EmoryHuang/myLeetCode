/*
 * @Descroption: LeetCode 1911. 最大子序列交替和
 * @Author: EmoryHuang
 * @Date: 2021-07-22 15:10:33
 * @解题思路:
 * 动态规划
 * odd[i],even[i]分别代表前i个数组的子序列中，最后一个元素的下标为奇数/偶数
 * 选择/不选择当前元素
 * 对odd来说，前一个选择的元素下标是偶数的
 * 对于even来说，前一个选择的元素下标是奇数的
 * odd[i] = max(even[i - 1] - nums[i], odd[i - 1])
 * even[i] = max(odd[i - 1] + nums[i], even[i - 1])
 */

class Solution {
   public:
    // long long maxAlternatingSum(vector<int>& nums) {
    //     int n = nums.size();
    //     // odd[i],even[i]分别代表前i个数组的子序列中，最后一个元素的下标为奇数/偶数
    //     vector<long long> odd(n), even(n);
    //     odd[0] = 0;
    //     even[0] = nums[0];
    //     for (int i = 1; i < n; i++) {
    //         // 选择/不选择当前元素
    //         // 对odd来说，前一个选择的元素下标是偶数的
    //         // 对于even来说，前一个选择的元素下标是奇数的
    //         odd[i] = max(even[i - 1] - nums[i], odd[i - 1]);
    //         even[i] = max(odd[i - 1] + nums[i], even[i - 1]);
    //     }
    //     return max(odd[n - 1], even[n - 1]);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long odd = 0, even = nums[0];
        for (int i = 1; i < n; i++) {
            odd = max(even - nums[i], odd);
            even = max(odd + nums[i], even);
        }
        return even;
    }
};