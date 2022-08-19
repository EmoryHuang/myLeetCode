/*
 * @Descroption: LeetCode 395. 至少有 K 个重复字符的最长子串
 * @Author: EmoryHuang
 * @Date: 2021-10-13 20:17:15
 * @Method:
 * 双指针
 * 由于只会出现小写字母，可以遍历出现字母的数量
 * 记录有多少字符符合要求，当区间内所有字符都符合时更新答案
 */

class Solution {
   public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        // 遍历出现字母的数量
        for (int p = 1; p <= 26; ++p) {
            vector<int> hash(26);
            int l = 0, r = 0;
            // cnt 表示出现的字母数量，total 表示满足条件的字母数量
            int cnt = 0, total = 0;
            for (int r = 0; r < s.size(); r++) {
                int u = s[r] - 'a';
                hash[u]++;
                if (hash[u] == 1) cnt++;    // 出现了新字母
                if (hash[u] == k) total++;  // 出现了满足条件的字母
                // 出现字母的数量大于 p
                while (cnt > p) {
                    int v = s[l++] - 'a';
                    hash[v]--;
                    if (hash[v] == 0) cnt--;
                    if (hash[v] == k - 1) total--;
                }
                if (cnt == total) ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};