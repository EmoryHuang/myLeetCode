/*
 * @Descroption: LeetCode 1688. 比赛中的配对次数
 * @Author: EmoryHuang
 * @Date: 2021-11-08 20:32:30
 * @Method:
 * 简单题，模拟计数配对次数
 */

class Solution {
   public:
    int numberOfMatches(int n) {
        if (n == 1) return 0;
        int ans = 0;
        while (n != 1) {
            if (n & 1) {
                ans += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            } else {
                ans += n / 2;
                n /= 2;
            }
        }
        return ans;
    }
};