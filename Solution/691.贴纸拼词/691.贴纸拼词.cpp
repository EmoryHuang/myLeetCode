/*
 * @Descroption: LeetCode 691. 贴纸拼词
 * @Author: EmoryHuang
 * @Date: 2022-05-14 09:23:42
 * @Method:
 * 记忆化搜索 + 状态压缩
 * 使用 mask 来表示 target 中的每个字母是否找到
 * 遍历 stickers 中的每个字符串，来寻找 target 中缺失的字符
 * 如果当前字符不存在并且在 sticker 中，则更新 mask 并继续向下搜索
 */

class Solution {
   public:
    int m;
    int dfs(int mask, vector<int>& dp, vector<string>& stickers, string target) {
        // mask 表示 target 当前缺失字符的位置
        if (dp[mask] != -1) return dp[mask];
        dp[mask] = m + 1;

        // 遍历 stickers 中的每个字符串，来寻找 target 中缺失的字符
        for (auto sticker : stickers) {
            int cur = mask;  // 当前状态

            vector<int> cnt(26);
            for (auto c : sticker) cnt[c - 'a']++;

            for (int i = 0; i < m; i++) {
                // 如果当前字符不存在并且在 sticker 中
                if (cnt[target[i] - 'a'] && (mask >> i & 1)) {
                    cnt[target[i] - 'a']--;
                    cur ^= 1 << i;  // 更新当前状态
                }
            }
            // 如果当前状态更小，则继续向下搜索
            if (cur < mask) dp[mask] = min(dp[mask], dfs(cur, dp, stickers, target) + 1);
        }
        return dp[mask];
    }
    int minStickers(vector<string>& stickers, string target) {
        m = target.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        // 初始化 mask 全为 1
        int ans = dfs((1 << m) - 1, dp, stickers, target);
        return ans > m ? -1 : ans;
    }
};