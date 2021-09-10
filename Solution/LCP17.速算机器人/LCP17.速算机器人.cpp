/*
 * @Descroption: LCP 17. 速算机器人
 * @Author: EmoryHuang
 * @Date: 2021-07-08 18:57:12
 * @解题思路:
 * 简单题，按照题目给的式子计算
 */

class Solution {
   public:
    int calculate(string s) {
        int x = 1, y = 0;
        for (auto c : s)
            if (c == 'A')
                x = 2 * x + y;
            else
                y = 2 * y + x;
        return x + y;
    }
};