/*
 * @Descroption: LeetCode 455. 分发饼干
 * @Author: EmoryHuang
 * @Date: 2021-06-08 19:48:00
 * @解题思路:
 * 贪心思想，对 s 和 g 进行排序，然后判断当前饼干是否可以满足当前孩子的需求
 */

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, cookies = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (cookies < s.size() && ans < g.size()) {
            // 当前饼干可以满足当前孩子的需求
            if (s[cookies] >= g[ans]) ans++;
            cookies++;
        }
        return ans;
    }
};