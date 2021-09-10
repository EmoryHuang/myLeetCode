/*
 * @Descroption: LeetCode 1456. 定长子串中元音的最大数目
 * @Author: EmoryHuang
 * @Date: 2021-08-08 14:49:49
 * @Method:
 * 滑动窗口，统计窗口内元音字母的数目，记录最大值
 */

class Solution {
   public:
    int maxVowels(string s, int k) {
        set<char> ls = {'a', 'e', 'i', 'o', 'u'};
        int l = 0, r = 0;
        int ans = 0, cnt = 0;
        while (r < s.size()) {
            if (ls.count(s[r++])) {
                cnt++;
                ans = max(ans, cnt);
            }
            if (r - l >= k)
                if (ls.count(s[l++])) cnt -= 1;
        }
        return ans;
    }
};