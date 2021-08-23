/*
 * @Descroption: LeetCode 1221. 分割平衡字符串
 * @Author: EmoryHuang
 * @Date: 2021-08-23 19:20:53
 * @Method:
 * 贪心，计数L和R的个数，若个数相等则记录并重置数量
 */

class Solution {
   public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, ans = 0;
        for (auto c : s) {
            if (c == 'L') l++;
            if (c == 'R') r++;
            if (l == r) {
                ans++;
                l = r = 0;
            }
        }
        return ans;
    }
};