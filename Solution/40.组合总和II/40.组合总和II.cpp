/*
 * @Descroption: LeetCode 40. 组合总和 II
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:34:17
 * @解题思路:
 * 回溯剪枝
 * 与[39. 组合总和]类似，旦这里每个数字在每个组合中只能使用一次
 *
 * 问题的关键在于去重，在搜索的过程中判断是否会出现重复集结果
 * 具体来说，当不是第一次循环，并且当前元素等于前一个元素时，跳过
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(vector<int> candidates, int target, int ind) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        if (target < 0) return;
        for (int i = ind; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                // 当不是第一次循环，并且当前元素等于前一个元素时，跳过
                if (i > ind && candidates[i] == candidates[i - 1]) continue;
                comb.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};