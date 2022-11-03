/*
 * @Descroption: LeetCode 1822. 数组元素积的符号
 * @Author: EmoryHuang
 * @Date: 2022-10-27 09:13:50
 * @Method:
 * 简单题，数负数的数量即可
 */

class Solution {
    public int arraySign(int[] nums) {
        int neg = 0;
        for (int num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                neg++;
        }
        return neg % 2 == 0 ? 1 : -1;
    }
}