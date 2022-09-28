/*
 * @Descroption: LeetCode 868. 二进制间距
 * @Author: EmoryHuang
 * @Date: 2022-04-23 08:45:30
 * @Method:
 * 位运算，记录二进制中两个1之间的最大距离
 */

class Solution {
   public:
    int binaryGap(int n) {
        int cnt = INT_MIN, ans = 0;
        while (n) {
            if (n & 1) {
                ans = max(ans, cnt);
                cnt = 1;
            } else
                cnt++;
            n >>= 1;
        }
        return ans;
    }
};