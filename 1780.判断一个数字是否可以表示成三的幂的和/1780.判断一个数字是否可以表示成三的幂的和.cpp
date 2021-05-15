/*
 * @Descroption: LeetCode 1780. 判断一个数字是否可以表示成三的幂的和
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:26:36
 * @解题思路:
 * 如果一个数字可以表示成三的幂的和，那么这个数字转换为三进制后，数字应该只有 0 和 1
 */

class Solution {
   public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};