/*
 * @Description: LeetCode 55. 跳跃游戏
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:31:25
 * @解题思路:
 * 贪心，维护当前能够到达的最大距离
 */

import java.util.*;

class Solution {
    public boolean canJump(int[] nums) {
        int dis = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > dis) {
                return false;
            }
            dis = Math.max(dis, i + nums[i]);
        }
        return true;
    }
}