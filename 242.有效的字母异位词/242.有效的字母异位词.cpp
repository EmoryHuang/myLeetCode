/*
 * @Descroption: LeetCode 242. 有效的字母异位词
 * @Author: EmoryHuang
 * @Date: 2021-05-28 13:19:17
 * @解题思路:
 * 方法一：sort
 * 使用sort之后直接判断字符串是否相等
 *
 * 方法二：map
 * 使用map计数，判断字母个数是否相同
 */

class Solution {
   public:
    // 方法一：sort
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     if (s == t) return true;
    //     return false;
    // }

    // 方法二：map
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        map<char, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->second != 0) return false;
        return true;
    }
};