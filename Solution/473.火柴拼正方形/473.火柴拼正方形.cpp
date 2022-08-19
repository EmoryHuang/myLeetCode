/*
 * @Descroption: LeetCode 473. 火柴拼正方形
 * @Author: EmoryHuang
 * @Date: 2021-05-08 21:18:36
 * @解题思路: 回溯 + 剪枝
 * 运用回溯的方法，`side[i]` 为第 `i` 边的长度，
 * 利用一个递归函数 `backtrack(i)` 递归地枚举第 `i` 个火柴的分配方案，
 * 过程中实时地更新 `side` 数组
 * 剪枝：
 * - 如果第`i`边已有长度`side[i]`+当前火柴长度 `matchsticks[num]`超过了`target`，那么不分配给第`i`边
 * - 如果当前边没有火柴，那么下一个边也必然没有火柴
 * - 如果当前边恰能达到 target，那么不分配
 */

class Solution {
   public:
    bool backtrack(vector<int>& matchsticks, int num, vector<int>& side, int target) {
        if (num == matchsticks.size())  // 遍历完成
            return side[0] == side[1] && side[0] == side[2] && side[0] == side[3];
        for (int i = 0; i < side.size(); i++) {
            if (side[i] + matchsticks[num] > target) continue;  // 长度大于 target
            // 放当前火柴
            side[i] += matchsticks[num];
            // 然后在放下一个火柴
            if (backtrack(matchsticks, num + 1, side, target)) return true;  //回溯
            // 移除，放到其他边上
            side[i] -= matchsticks[num];
            // 如果当前边没有火柴，那么下一个边也必然没有火柴
            // 或者当前边恰能达到 target
            if (side[i] == 0 || side[i] + matchsticks[num] == target) break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int num : matchsticks) sum += num;
        if (sum == 0 || sum % 4 != 0) return false;
        vector<int> side(4);
        return backtrack(matchsticks, 0, side, sum / 4);
    }
};