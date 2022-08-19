/*
 * @Descroption: LeetCode 414. 第三大的数
 * @Author: EmoryHuang
 * @Date: 2021-10-06 14:32:58
 * @Method:
 * 遍历一次获取最大值，次大值，第三大值
 * 若遇到一个更大的值，则分别对值进行传递
 */

class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (int num : nums) {
            if (num == a || num == b || num == c) continue;
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (num > b) {
                c = b;
                b = num;
            } else if (num > c) {
                c = num;
            }
        }
        return c != LONG_MIN ? c : a;
    }
};