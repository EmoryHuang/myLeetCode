/*
 * @Descroption: LeetCode 1688. �����е���Դ���
 * @Author: EmoryHuang
 * @Date: 2021-11-08 20:32:30
 * @Method:
 * ���⣬ģ�������Դ���
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