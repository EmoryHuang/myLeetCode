/*
 * @Descroption: LeetCode 319. 灯泡开关
 * @Author: EmoryHuang
 * @Date: 2021-03-25 13:56:36
 * @解题思路:
 * 第 i 轮时，被切换的灯泡位置是 i 的倍数
 * 对于第 p 个灯泡来说，只有其第“因子”轮才会切换，若其有 q 个因子，则最终被切换 q 次
 * 只有平方数的因子个数不是成对出现，
 * 例如 `16 = 1 * 4 * 16`，而非平方数例如`15 = 1 * 3 * 5 * 15`
 * 那么题目最终转化为 `1~n` 里平方数的个数
 */

class Solution {
   public:
    int bulbSwitch(int n) { return sqrt(n); }
};