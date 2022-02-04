/*
 * @Descroption: LeetCode 1725. 可以形成最大正方形的矩形数目
 * @Author: EmoryHuang
 * @Date: 2022-02-04 10:22:58
 * @Method:
 * 简单题，枚举每个矩形能切出的最大正方形边长，然后求最大值并计数
 */

class Solution {
   public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, max_len = 0;
        for (auto rect : rectangles) {
            int w = rect[0], l = rect[1];
            int e = min(w, l);
            if (e > max_len) {
                max_len = e;
                ans = 1;
            } else if (e == max_len) {
                ans++;
            }
        }
        return ans;
    }
};