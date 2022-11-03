/*
 * @Descroption: LeetCode 1773. 统计匹配检索规则的物品数量
 * @Author: EmoryHuang
 * @Date: 2021-11-05 19:49:44
 * @Method:
 * 简单题，遍历数组进行匹配
 */

class Solution {
   public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx, ans = 0;
        if (ruleKey == "type")
            idx = 0;
        else if (ruleKey == "color")
            idx = 1;
        else
            idx = 2;
        for (auto item : items)
            if (item[idx] == ruleValue) ans++;
        return ans;
    }
};