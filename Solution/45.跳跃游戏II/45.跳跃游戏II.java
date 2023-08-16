/*
 * @Description: LeetCode 45. 跳跃游戏 II
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:39:40
 * @解题思路:
 * 贪心
 */

import java.util.*;

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int pos = 0, end = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            pos = Math.max(pos, i + nums[i]);
            if (i == end) {
                end = pos;
                ans++;
            }
        }
        return ans;
    }
}