/*
 * @Descroption: LeetCode 506. 相对名次
 * @Author: EmoryHuang
 * @Date: 2021-04-26 15:43:36
 * @解题思路: 使用 map 记录原始得分顺序，sort 排序后，根据名次输出
 */

class Solution {
   public:
    static bool cmp(int a, int b) { return a > b; }
    vector<string> findRelativeRanks(vector<int>& score) {
        int len = score.size();
        vector<string> ans(len);
        map<int, int> mp;
        for (int i = 0; i < len; i++) mp[score[i]] = i;  // 记录原始得分顺序
        sort(score.begin(), score.end(), cmp);
        for (int i = 0; i < len; i++) {
            if (i == 0)
                ans[mp[score[i]]] = "Gold Medal";
            else if (i == 1)
                ans[mp[score[i]]] = "Silver Medal";
            else if (i == 2)
                ans[mp[score[i]]] = "Bronze Medal";
            else
                ans[mp[score[i]]] = to_string(i + 1);
        }
        return ans;
    }
};