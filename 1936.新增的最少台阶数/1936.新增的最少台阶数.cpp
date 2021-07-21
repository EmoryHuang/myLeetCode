/*
 * @Descroption: LeetCode 1936. 新增的最少台阶数
 * @Author: EmoryHuang
 * @Date: 2021-07-21 21:10:05
 * @解题思路:
 * 贪心
 * 维护当前位置 pos
 * 如果能登上这个台阶, 则登上这个台阶
 * 如果不能登上这个台阶，添加台阶到能登上为止
 */

class Solution {
   public:
    int addRungs(vector<int>& rungs, int dist) {
        int pos = 0, cnt = 0;
        for (int rung : rungs) {
            // 如果不能登上这个台阶
            // 贪心添加台阶
            if (pos + dist < rung) cnt += (rung - pos - 1) / dist;
            pos = rung;  // 登上这个台阶
        }
        return cnt;
    }
};