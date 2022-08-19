/*
 * @Descroption: LeetCode 492. 构造矩形
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:17:36
 * @解题思路:
 * 首先用 sqrt 开方，之后寻找最接近这个数的 area 的因子，即可得到长或宽
 */

class Solution {
   public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0) w--;
        return {area / w, w};
    }
};