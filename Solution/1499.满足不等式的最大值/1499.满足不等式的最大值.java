/*
 * @Descroption: LeetCode 1499. 满足不等式的最大值
 * @Author: EmoryHuang
 * @Date: 2023-07-21 09:16:55
 * @Method:
 * 小根堆存储 x - y，即 -x + y 的最大值
 */

import java.util.*;

class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int ans = Integer.MIN_VALUE;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < points.length; i++) {
            int x = points[i][0], y = points[i][1];
            while (!q.isEmpty() && x - q.peek()[1] > k) {
                q.poll();
            }
            if (!q.isEmpty()) {
                ans = Math.max(ans, x + y - q.peek()[0]);
            }
            q.offer(new int[] { x - y, x });
        }
        return ans;
    }
}