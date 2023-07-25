/*
 * @Descroption: LeetCode 1466. 重新规划路线
 * @Author: EmoryHuang
 * @Date: 2023-07-17 10:39:35
 * @Method:
 * 把图变为一个无向图，然后把顺着的边的权重设置为1，把逆着的权重设置为0，然后从0开始做BFS，顺道累加权重
 */

import java.util.*;

class Solution {
    public int minReorder(int n, int[][] connections) {
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] c : connections) {
            graph[c[0]].add(new int[] { c[1], 1 });
            graph[c[1]].add(new int[] { c[0], 0 });
        }
        int ans = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        boolean[] visited = new boolean[n];
        visited[0] = true;
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int[] c : graph[u]) {
                int v = c[0], w = c[1];
                if (visited[v]) {
                    continue;
                }
                visited[v] = true;
                ans += w;
                queue.offer(v);
            }
        }
        return ans;
    }
}