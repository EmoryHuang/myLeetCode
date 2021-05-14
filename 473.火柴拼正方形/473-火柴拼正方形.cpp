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