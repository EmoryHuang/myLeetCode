/*
 * @Descroption: LeetCode 438. 找到字符串中所有字母异位词
 * @Author: EmoryHuang
 * @Date: 2021-11-28 18:51:52
 * @Method:
 * 滑动窗口
 * 比较滑动窗口中的词频与字符串中的词频是否一致
 * 词频相等则将左端点加入结果
 * */

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sl = s.length(), pl = p.length();
        vector<int> ans, p_cnt(26, 0), s_cnt(26, 0);
        for (int i = 0; i < pl; i++) p_cnt[p[i] - 'a']++;
        int l = 0;
        for (int r = 0; r < sl; r++) {
            s_cnt[s[r] - 'a']++;
            if (r - l + 1 > pl) {
                s_cnt[s[l++] - 'a']--;
            }
            if (s_cnt == p_cnt) ans.push_back(l);
        }
        return ans;
    }
};