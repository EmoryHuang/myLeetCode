/*
 * @Descroption: LeetCode 848. 字母移位
 * @Author: EmoryHuang
 * @Date: 2021-06-13 15:57:00
 * @解题思路:
 * 计算后缀和，然后统一移位
 */

class Solution {
   public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = shifts.size() - 2; i >= 0; i--) shifts[i] += shifts[i + 1] % 26;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char tmp = (s[i] - 'a' + shifts[i]) % 26 + 'a';
            ans += tmp;
        }
        return ans;
    }
};
