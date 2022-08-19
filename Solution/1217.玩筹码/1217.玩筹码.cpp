/*
 * @Descroption: LeetCode 1217. 玩筹码
 * @Author: EmoryHuang
 * @Date: 2021-09-11 20:27:09
 * @Method:
 * 奇数移动到奇数位置无消耗，偶数移动到偶数位置无消耗
 * 那么只需要统计奇数偶数的数量，然后在选择数量较少的一方
 */

class Solution {
   public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int num : position) {
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }
        return min(odd, even);
    }
};