/*
 * @Descroption: LeetCode 821. 字符的最短距离
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:34:00
 * @解题思路:
 * 从左向右遍历，记录上一个字符 C 出现的位置 prev，那么答案就是 i - prev。
 * 从右向左遍历，记录上一个字符 C 出现的位置 prev，那么答案就是 prev - i。
 * 这两个值取最小就是答案。
 */

class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size());
        int pre = -0x3f3f3f3f;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) pre = i;
            ans[i] = i - pre;
        }
        pre = 0x3f3f3f3f;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c) pre = i;
            ans[i] = min(ans[i], pre - i);
        }
        return ans;
    }
};