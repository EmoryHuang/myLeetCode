/*
 * @Descroption: LeetCode 216. 组合总和 III
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:00:30
 * @Method:
 * 回溯法
 */

import java.util.*;

class Solution {
    List<Integer> temp = new ArrayList<>();
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }

    void dfs(int cur, int k, int sum) {
        if (k == 0 && sum == 0) {
            ans.add(new ArrayList<Integer>(temp));
        } else {
            for (int i = cur; i <= 9 && i <= sum; i++) {
                temp.add(i);
                dfs(i + 1, k - 1, sum - i);
                temp.remove(temp.size() - 1);
            }
        }
    }
}