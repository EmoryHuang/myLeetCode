/*
 * @Descroption: LeetCode 292. Nim 游戏
 * @Author: EmoryHuang
 * @Date: 2021-05-20 17:45:37
 * @解题思路:
 * 如果小于3块的话，你作为先手就可以全拿走，结束游戏。
 * 如果恰好有四块石头，你就会失败。
 * 但是如果不是4倍数的话，就可以控制将4个留给对手，那么自己必定会赢
 */

class Solution {
   public:
    bool canWinNim(int n) { return n % 4 != 0; }
};