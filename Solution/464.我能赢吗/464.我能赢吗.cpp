/*
 * @Descroption: LeetCode 464. 我能赢吗
 * @Author: EmoryHuang
 * @Date: 2022-05-22 10:51:50
 * @Method:
 * 状态压缩 DP
 * 枚举所有可能的状态，使用 memo 记录当前使用的数字并记录 total
 * 如果当前数字已经被选过了，则跳过；如果当前数字加上之前的数字大于目标值，则赢了
 */


class Solution {
   public:
    int maxChoosableInteger, desiredTotal;
    unordered_map<int, bool> cache;
    bool dfs(int memo, int total) {
        if (!cache.count(memo)) {
            bool res = false;
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (((memo >> i) & 1) == 0) {
                    if (total + i + 1 >= desiredTotal) {
                        res = true;
                        break;
                    }
                    if (!dfs(memo | (1 << i), total + i + 1)) {
                        res = true;
                        break;
                    }
                }
            }
            cache[memo] = res;
        }
        return cache[memo];
    }
    bool canIWin(int _maxChoosableInteger, int _desiredTotal) {
        maxChoosableInteger = _maxChoosableInteger;
        desiredTotal = _desiredTotal;
        if (desiredTotal == 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        return dfs(0, 0);
    }
};