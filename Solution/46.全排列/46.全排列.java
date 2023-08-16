/*
 * @Description: LeetCode 46. 全排列
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:51:30
 * @解题思路:
 * 回溯
 */

import java.util.*;

class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        dfs(nums, new boolean[nums.length], new ArrayList<>());
        return ans;
    }

    void dfs(int[] nums, boolean[] vis, List<Integer> cur) {
        if (nums.length == cur.size()) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!vis[i]) {
                cur.add(nums[i]);
                vis[i] = true;
                dfs(nums, vis, cur);
                cur.remove(cur.size() - 1);
                vis[i] = false;
            }
        }
    }
}