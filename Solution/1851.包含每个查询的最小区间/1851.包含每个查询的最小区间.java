/*
 * @Descroption: LeetCode 1466. 重新规划路线
 * @Author: EmoryHuang
 * @Date: 2023-07-18 09:33:48
 * @Method:
 * 排序 + 优先队列
 */

import java.util.*;

class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        // 按照区间左端点排序
        Arrays.sort(intervals, (o1, o2) -> {
            return o1[0] - o2[0];
        });
        int n = queries.length, m = intervals.length;
        // 记录 queries idx
        int[][] que = new int[n][2];
        for (int i = 0; i < n; i++) {
            que[i][0] = queries[i];
            que[i][1] = i;
        }
        Arrays.sort(que, (o1,o2) -> {
            return o1[0] - o2[0];   
        });
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        // 小根堆，根据区间长度排序
        PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> {
            return (o1[1] - o1[0]) - (o2[1] - o2[0]);
        });
        int idx = 0;
        for(int i = 0 ; i < n;i++) {
            // 满足条件的左端点
            while (idx < m && que[i][0] >= intervals[idx][0]) {
                queue.offer(new int[]{intervals[idx][0], intervals[idx][1]});
                idx++;
            }
            while (!queue.isEmpty() && queue.peek()[1] < que[i][0]) {
                queue.poll();
            }
            if (!queue.isEmpty()) {
                int[] cur = queue.peek();
                ans[que[i][1]] = cur[1] - cur[0] + 1;
            }
        }
        return ans;
    }
}