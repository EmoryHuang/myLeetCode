/*
 * @Description: LeetCode 118. 杨辉三角
 * @Author: EmoryHuang
 * @Date: 2023-08-16 10:02:20
 * @解题思路:
 * 动态规划
 * dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
 */

import java.util.*;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j));
                }
            }
            ans.add(row);
        }
        return ans;
    }
}