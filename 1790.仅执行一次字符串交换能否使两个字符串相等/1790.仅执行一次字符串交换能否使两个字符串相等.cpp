/*
 * @Descroption: LeetCode 1790. 仅执行一次字符串交换能否使两个字符串相等
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:12:43
 * @Method:
 * 简单题，记录对应位置不相同的元素个数
 */

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        vector<int> mp(26);
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            mp[s1[i] - 'a']++;
            mp[s2[i] - 'a']--;
            if (s1[i] != s2[i]) cnt++;
        }
        for (int num : mp)
            if (num != 0) return false;
        return cnt == 2;
    }
};