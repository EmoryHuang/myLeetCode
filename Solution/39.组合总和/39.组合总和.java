/*
 * @Description: LeetCode 39. 组合总和
 * @Author: EmoryHuang
 * @Date: 2023-08-14 10:16:40
 * @解题思路:
 * 回溯
 */

import java.util.*;

class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        dfs(candidates, target, 0, new ArrayList<>());
        return ans;
    }

    void dfs(int[] candidates, int target, int idx, List<Integer> cur) {
        if (target == 0) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = idx; i < candidates.length; i++) {
            cur.add(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur);
            cur.remove(cur.size() - 1);
        }
    }
}