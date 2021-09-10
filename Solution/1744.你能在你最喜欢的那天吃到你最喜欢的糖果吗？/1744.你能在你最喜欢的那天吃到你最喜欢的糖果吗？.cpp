/*
 * @Descroption: LeetCode 1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 * @Author: EmoryHuang
 * @Date: 2021-06-01 19:57:00
 * @解题思路:
 * 求出糖果数量的前缀和
 * 由此可以得到第 i 种糖果编号范围为 [pre[i]+1, pre[i] + candiesCount[i]]
 * 另外一方面，每天至少吃 1 颗糖果，至多吃 Capi 颗糖果
 * 因此吃的糖果的数量落在区间 [dayi + 1, (dayi + 1) * Capi]
 * 只要判断这两个区间是否有交集即可
 */

class Solution {
   public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> pre(n + 1);
        vector<bool> ans;
        // 计算前缀和
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + candiesCount[i];
        for (auto query : queries) {
            long long cap = query[2];
            long long minCandy = query[1] + 1;  // 到喜欢的那天至少能吃到的数量
            long long maxCandy = (query[1] + 1) * cap;  // 到喜欢的那天至多能吃到的数量
            long long firstCandy = pre[query[0]] + 1;   // 第一个喜欢的糖果
            long long lastCandy = pre[query[0]] + candiesCount[query[0]];  // 最后一个喜欢的糖果
            ans.push_back(lastCandy >= minCandy && firstCandy <= maxCandy);
        }
        return ans;
    }
};