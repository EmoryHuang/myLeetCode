/*
 * @Descroption: LeetCode 1743. 从相邻元素对还原数组
 * @Author: EmoryHuang
 * @Date: 2021-07-25 13:38:33
 * @解题思路:
 * 使用哈希表存储相邻元素
 * 其中，首尾元素只会出现一次，因此，只需要先找出首尾元素
 * 然后按照相邻元素寻找即可
 */

class Solution {
   public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> hash;
        for (auto pair : adjacentPairs) {
            hash[pair[0]].push_back(pair[1]);
            hash[pair[1]].push_back(pair[0]);
        }
        vector<int> ans;
        int n = adjacentPairs.size() + 1;
        for (auto [key, value] : hash) {
            // 首尾元素只出现一次
            if (value.size() == 1) {
                // 加入首元素和相邻的元素
                ans.push_back(key);
                ans.push_back(value[0]);
                break;
            }
        }
        for (int i = 2; i < n; i++) {
            // 上一个元素的相邻元素
            auto next = hash[ans[i - 1]];
            ans.push_back(next[0] == ans[i - 2] ? next[1] : next[0]);
        }
        return ans;
    }
};