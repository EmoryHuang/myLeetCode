/*
 * @Descroption: LeetCode 1344. 时钟指针的夹角
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:11:33
 * @解题思路:
 * 计算时针和分针走的角度，取较小的那个
 */

class Solution {
   public:
    double angleClock(int hour, int minutes) {
        // 时针一小时走30度，一分钟走 30 / 60 = 0.5度
        double harg = hour * 30 + minutes * 0.5;
        // 分针一分钟走 360 / 60 = 6度
        double marg = minutes * 6;
        if (abs(harg - marg) < 180)
            return abs(harg - marg);
        else
            return 360 - abs(harg - marg);
    }
};