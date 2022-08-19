/*
 * @Descroption: LeetCode 1513. 仅含 1 的子串数
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:43:15
 * @Method:
 * 简单题，数学，统计连续字串可组成的仅含 1 的子串数
 */

class Solution {
   public:
    int numSub(string s) {
        long ans = 0, cnt = 0;
        for (auto c : s) {
            if (c == '1')
                ans += ++cnt;
            else
                cnt = 0;
        }
        return ans % 1000000007;
    }
};