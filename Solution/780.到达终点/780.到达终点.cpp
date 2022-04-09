/*
 * @Descroption: LeetCode 780. 到达终点
 * @Author: EmoryHuang
 * @Date: 2022-04-09 08:58:23
 * @Method:
 * 从终点反向递推至起点
 * 转换是从点 (x, y) 转换到 (x, x+y) 或者 (x+y, y)
 * 反向递推时, 每次使用 tx, ty 中的较大值减去较小值, 使得不断逼近起点
 *
 * 为了快速逼近, 可以每次将较大值一次性减去多倍的较小值, 从而减少迭代次数
 */

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (sx == tx && sy == ty) return true;
            if (tx > ty) {
                tx -= ty * max((tx - sx) / ty, 1);
            } else {
                ty -= tx * max((ty - sy) / tx, 1);
            }
        }
        return false;
    }
};