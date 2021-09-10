/*
 * @Descroption: LeetCode 541. 反转字符串 II
 * @Author: EmoryHuang
 * @Date: 2021-08-20 15:29:10
 * @Method:
 * 模拟，按题意每个 2k 个字符反转前 k 个
 */

class Solution {
   public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k, n);
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};