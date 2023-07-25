/*
 * @Descroption: LeetCode 841. 钥匙和房间
 * @Author: EmoryHuang
 * @Date: 2023-07-17 10:11:14
 * @Method:
 * BFS
 * 检查可访问点的数量
 */

import java.util.*;

class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Deque<Integer> queue = new ArrayDeque<>();
        Set<Integer> hash = new HashSet<>();
        queue.offer(0);
        hash.add(0);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int next : rooms.get(cur)) {
                if (!hash.contains(next)) {
                    queue.offer(next);
                    hash.add(next);
                }
            }
        }
        return hash.size() == rooms.size();
    }
}