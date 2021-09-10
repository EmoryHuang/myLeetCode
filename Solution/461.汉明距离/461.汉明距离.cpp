/*
 * @Descroption: LeetCode 461. 汉明距离
 * @Author: EmoryHuang
 * @Date: 2021-05-27 19:48:17
 * @解题思路:
 * 检查 d 的最低位，如果最低位为 1，那么令计数器加一，然后令 d 整体右移一位
 */

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int d = x ^ y;
        int ans = 0;
        while (d) {
            ans += d & 1;
            d >>= 1;
        }
        return ans;
    }
};