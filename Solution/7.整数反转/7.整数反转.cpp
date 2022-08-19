/*
 * @Descroption: LeetCode 7. 整数反转
 * @Author: EmoryHuang
 * @Date: 2021-03-18 13:31:36
 * @解题思路:
 * 整数反转问题，可以直接利用求模运算来反转，思路还是简单的，相比于笨笨的再转化成字符串，数学方法也简单明了多了
 */

class Solution {
   public:
    int reverse(int x) {
        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;  //求尾数
            x /= 10;
        }
        if (ans > INT_MAX || ans < INT_MIN)  //判断越界
            return 0;
        else
            return ans;
    }
};