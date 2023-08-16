/*
 * @Description: LeetCode 347. 前 K 个高频元素
 * @Author: EmoryHuang
 * @Date: 2023-08-15 10:12:25
 * @解题思路:
 * 使用小根堆存储出现频率前 k 高的元素
 */

import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> hash = new HashMap<>();
        for (int num : nums) {
            hash.put(num, hash.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<int[]> queue = new PriorityQueue<>((int[] a, int[] b) -> a[1] - b[1]);
        for (Map.Entry<Integer, Integer> entry : hash.entrySet()) {
            int num = entry.getKey(), cnt = entry.getValue();
            if (queue.size() == k) {
                if (queue.peek()[1] < cnt) {
                    queue.poll();
                    queue.offer(new int[]{num, cnt});
                }
            } else {
                queue.offer(new int[]{num, cnt});
            }
        }
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = queue.poll()[0];
        }
        return ans;
    }
}