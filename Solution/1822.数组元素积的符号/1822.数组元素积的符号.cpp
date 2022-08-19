/*
 * @Descroption: LeetCode 1822. 数组元素积的符号
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:41:00
 * @解题思路:
 * 简单题，数负数的数量，最后判断乘积结果
 */

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                neg++;
        }
        return neg % 2 == 0 ? 1 : -1;
    }
};