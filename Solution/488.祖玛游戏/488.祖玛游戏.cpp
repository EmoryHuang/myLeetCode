/*
 * @Descroption: LeetCode 488. 祖玛游戏
 * @Author: EmoryHuang
 * @Date: 2021-11-09 15:52:52
 * @Method:
 * dfs + 剪枝
 * 爆搜，遍历手中球以及可以插入的每个位置，求最小的插入次数
 * 使用一个 int 来记录 hand 的使用情况
 */

class Solution {
    int INF = 0x3f3f3f3f;
    string b;
    int m;
    unordered_map<string, int> map;

    int dfs(string &a, int cur) {
        if (a.length() == 0) return 0;
        if (map.count(a)) return map[a];
        int ans = INF;
        int n = a.length();
        //遍历手中球
        for (int i = 0; i < m; ++i) {
            //如果当前球已经被取过，则跳过该球
            if (((cur >> i) & 1) == 1) continue;
            //给当前取的球做标记
            int next = (1 << i) | cur;
            //遍历插入球位置
            for (int j = 0; j <= n; ++j) {
                string s = "";
                s += a.substr(0, j) + b[i];
                if (j != n) s += a.substr(j);
                int k = j;
                while (0 <= k && k < s.length()) {
                    char c = s[k];
                    int l = k, r = k;
                    //中心扩散搜索连续大于等于三个字符,然后删除
                    while (l >= 0 && s[l] == c) l--;
                    while (r < s.length() && s[r] == c) r++;
                    if (r - l - 1 >= 3) {
                        s.erase(l + 1, r - l - 1);
                        k = l >= 0 ? l : r;
                    } else {
                        break;
                    }
                }
                ans = min(ans, dfs(s, next) + 1);
            }
        }
        map[a] = ans;
        return ans;
    }

   public:
    int findMinStep(string board, string hand) {
        b = hand;
        m = hand.length();
        int ans = dfs(board, 1 << m);
        return ans == INF ? -1 : ans;
    }
};