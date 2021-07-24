/*
 * @Descroption: LeetCode 1736. 替换隐藏数字得到的最晚时间
 * @Author: EmoryHuang
 * @Date: 2021-07-24 13:09:37
 * @解题思路:
 * 贪心思想
 * 枚举所有 ? 可能出现的位置
 */

class Solution {
   public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = time[1] == '?' || time[1] < '4' ? '2' : '1';
        if (time[1] == '?') time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};