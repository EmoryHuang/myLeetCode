/*
 * @Description: LeetCode 78. 子集
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:55:50
 * @解题思路:
 * 回溯
 */

import java.util.*;

class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        dfs(nums, 0, new ArrayList<>());
        return ans;
    }

    void dfs(int[] nums, int idx, List<Integer> cur) {
        ans.add(new ArrayList<>(cur));
        for (int i = idx; i < nums.length; i++) {
            cur.add(nums[i]);
            dfs(nums, i + 1, cur);
            cur.remove(cur.size() - 1);
        }
    }
}