/*
 * @Descroption: LeetCode 2462. 雇佣 K 位工人的总代价
 * @Author: EmoryHuang
 * @Date: 2023-07-20 10:21:58
 * @Method:
 * 分别维护左右两个堆，并通过左右两个指针进行值的添加
 */

import java.util.*;

class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        long ans = 0L;
        int left = 0, right = costs.length - 1;
        PriorityQueue<Integer> leftHeap = new PriorityQueue<>();
        PriorityQueue<Integer> rightHeap = new PriorityQueue<>();
        while (k != 0) {
            while (leftHeap.size() < candidates && left <= right) {
                leftHeap.offer(costs[left++]);
            }
            while (rightHeap.size() < candidates && left <= right) {
                rightHeap.offer(costs[right--]);
            }
            int x = leftHeap.isEmpty() ? Integer.MAX_VALUE : leftHeap.peek();
            int y = rightHeap.isEmpty() ? Integer.MAX_VALUE : rightHeap.peek();
            if (x <= y) {
                ans += x;
                leftHeap.poll();
            } else {
                ans += y;
                rightHeap.poll();
            }
            k--;
        }
        return ans;
    }
}