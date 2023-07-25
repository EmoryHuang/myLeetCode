/*
 * @Descroption: LeetCode 874. 模拟行走机器人
 * @Author: EmoryHuang
 * @Date: 2023-07-19 09:25:50
 * @Method:
 * 模拟
 * 使用哈希表记录障碍物位置
 */

import java.util.*;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        int px = 0, py = 0, d = 1;
        Set<Integer> set = new HashSet<Integer>();
        for (int[] obstacle : obstacles) {
            set.add(obstacle[0] * 60001 + obstacle[1]);
        }
        int ans = 0;
        for (int c : commands) {
            if (c < 0) {
                d += c == -1 ? 1 : -1;
                d %= 4;
                if (d < 0) {
                    d += 4;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    if (set.contains((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    ans = Math.max(ans, px * px + py * py);
                }
            }
        }
        return ans;
    }
}