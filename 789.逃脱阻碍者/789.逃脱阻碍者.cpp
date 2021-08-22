/*
 * @Descroption: LeetCode 789. 逃脱阻碍者
 * @Author: EmoryHuang
 * @Date: 2021-08-22 19:48:44
 * @Method:
 * 将题目换个说法，也就是比较是否有阻碍者比人物先到达目的地
 */

class Solution {
   public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d = abs(target[0]) + abs(target[1]);
        for (auto ghost : ghosts) {
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= d) return false;
        }
        return true;
    }
};