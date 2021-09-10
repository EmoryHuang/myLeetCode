/*
 * @Descroption: LeetCode 1276. 不浪费原料的汉堡制作方案
 * @Author: EmoryHuang
 * @Date: 2021-07-17 15:37:16
 * @解题思路:
 * 简单来说，就是求二元一次方程
 * 4x + 2y = tomatoSlices
 * x + y = cheeseSlices
 */

class Solution {
   public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices * 2 || cheeseSlices * 4 < tomatoSlices) {
            return {};
        }
        return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
    }
};