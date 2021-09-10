/*
 * @Descroption: LeetCode 39. 组合总和
 * @Author: EmoryHuang
 * @Date: 2021-05-27 21:33:17
 * @解题思路:
 * 递归+回溯
 * 通过递归寻找所有和为target的组合
 * 为了避免重复组合，需要先对candidates进行排序
 * 剪枝：若 num 小于当前组合的最后一个数 comb.back() >= num，才能继续
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(vector<int>& candidates, int target) {
        if (target == 0) ans.push_back(comb);
        if (target < 0) return;
        for (int num : candidates) {
            if (comb.size() == 0 || comb.back() >= num) {
                comb.push_back(num);
                dfs(candidates, target - num);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target);
        return ans;
    }
};