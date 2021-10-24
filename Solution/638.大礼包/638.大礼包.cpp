/*
 * @Descroption: LeetCode 638. 大礼包
 * @Author: EmoryHuang
 * @Date: 2021-10-24 18:59:58
 * @Method:
 * dfs 记忆化
 * 使用 cache 记录出现的子问题
 * 首先考虑在当前需求下不购买大礼包的花费，然后遍历每个大礼包，判断是否符合需求
 * 对于符合要求的大礼包，更新需求
 * 然后递归的求解不同需求下的最小花费
 */

class Solution {
   public:
    map<vector<int>, int> _cache;
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& cur) {
        // 如果出现过子问题，直接返回
        if (_cache[cur]) return _cache[cur];
        int ans = 0;
        // 不购买大礼包
        for (int i = 0; i < cur.size(); i++) ans += cur[i] * price[i];
        // 遍历每个礼包
        for (int i = 0; i < special.size(); i++) {
            vector<int> nxt = cur;
            bool flag = true;
            for (int j = 0; j < price.size(); j++) {
                // 大礼包中商品的数量不能超过需求量
                if (special[i][j] > cur[j]) {
                    flag = false;
                    break;
                }
            }
            // 当前大礼包不符合需求
            if (!flag) continue;
            // 更新需求量
            for (int j = 0; j < price.size(); j++) nxt[j] -= special[i][j];
            ans = min(ans, dfs(price, special, nxt) + special[i].back());
        }
        _cache[cur] = ans;
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};