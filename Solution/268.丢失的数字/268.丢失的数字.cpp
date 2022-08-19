/*
 * @Descroption: LeetCode 268. 丢失的数字
 * @Author: EmoryHuang
 * @Date: 2021-03-21 16:08:36
 * @解题思路:
 * 我首先想到的是数学方法，数列求和，然后减去有的数，剩下的就是缺失的数（就是可能有溢出的风险，算了不管了）
 *
 * 第二个方法是异或运算（总是想不到位运算方法），思想如下：
 * 一共有 n 个数，下标一定是从 0 到 n - 1，而数字也一定在 [0, n] 范围内。
 * 如果 n 是缺失的数，那么下标和数字都为[0, n - 1] ，异或完就是 0，所以剩下的初始值 n 就是缺失的值
 * 如果 n 不是缺失的数，那么数字中的 n 就能和初始值 n 异或得到 0，
 * 然后在下标和数字能匹配的都异或变成 0 了，除了只在下标中有而数字中没有的那个数，就是我们要的答案
 */

class Solution {
   public:
    // 方法一：数学方法
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum;
        sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) sum -= nums[i];
        return sum;
    }

    // 方法二：异或运算
    // int missingNumber(vector<int>& nums) {
    //     int ans = nums.size();
    //     for (int i = 0; i < nums.size(); i++) ans ^= i ^ nums[i];
    //     return ans;
    // }
};
