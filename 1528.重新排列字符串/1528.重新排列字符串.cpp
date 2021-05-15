/*
 * @Descroption: LeetCode 1528. 重新排列字符串
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:09:36
 * @解题思路:
 * 简单题，创建字符串，然后将位置与字符对应即可
 */

class Solution {
   public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};