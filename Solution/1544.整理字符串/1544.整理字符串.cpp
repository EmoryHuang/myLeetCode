/*
 * @Descroption: LeetCode 1544. 整理字符串
 * @Author: EmoryHuang
 * @Date: 2021-04-22 14:29:36
 * @解题思路:
 * 遍历字符串，将`ans`中最后一个元素与当前字符比较，若`ans`非空并且两者的 ACSII 相差 32，
 * 则去掉`ans`中的最后一个元素，否则加入
 */

class Solution {
   public:
    string makeGood(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (!ans.empty() && abs(ans.back() - s[i]) == 32)
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};