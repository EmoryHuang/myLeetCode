/*
 * @Descroption: LeetCode 1486. 数组异或操作
 * @Author: EmoryHuang
 * @Date: 2021-05-07 19:14:36
 * @解题思路:
 * 简单题，连异或都不需要了解
 */

class Solution {
   public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i = 1; i < n; i++) ans ^= start + 2 * i;
        return ans;
    }
};