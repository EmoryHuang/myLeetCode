/*
 * @Descroption: LeetCode 599. 两个列表的最小索引总和
 * @Author: EmoryHuang
 * @Date: 2022-03-14 08:52:53
 * @Method:
 * 简单题，使用哈希表记录 list1 每个元素的索引
 * 然后在 list2 中寻找 list1 中的元素，并维护最小索引和
 */

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> hash;
        for (int i = 0; i < list1.size(); i++) hash[list1[i]].push_back(i);
        vector<string> ans;
        int min_idx = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            string name = list2[i];
            if (hash.count(name)) {
                int idx = hash[name][0] + i;
                if (idx < min_idx) {
                    min_idx = idx;
                    ans.clear();
                    ans.push_back(name);
                } else if (idx == min_idx)
                    ans.push_back(name);
            }
        }
        return ans;
    }
};