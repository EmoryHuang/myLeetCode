/*
 * @Descroption: LeetCode 1503. 所有蚂蚁掉下来前的最后一刻
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:20:36
 * @解题思路:
 * 题目要求的是最后一只蚂蚁从木板上掉下来的时刻，所以并不需要区分每只蚂蚁。
 * 而且改变移动方向后的移动速度不变，
 * 因此，两只相遇的蚂蚁同时改变移动方向之后的情形等价于两只蚂蚁都不改变移动方向
 * 因此题目就变成了求蚂蚁需要爬行的最长路径
 */

class Solution {
   public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for (int i = 0; i < left.size(); i++) time = max(time, left[i]);
        for (int i = 0; i < right.size(); i++) time = max(time, n - right[i]);
        return time;
    }
};