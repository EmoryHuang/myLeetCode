/*
 * @Descroption: LeetCode 2542. 最大子序列的分数
 * @Author: EmoryHuang
 * @Date: 2023-07-20 10:04:58
 * @Method:
 * 根据 nums2 进行排序
 * 通过小根堆维护 nums1 中的和
 */

import java.util.*;

class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; i ++){
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> nums2[j] - nums2[i]);
        long sum = 0L;
        long ans = 0L;
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int idx : idxs) {
            int num1 = nums1[idx], num2 = nums2[idx];
            heap.offer(num1);
            sum += num1;
            while (heap.size() > k) {
                sum -= heap.poll();
            }
            if (heap.size() == k) {
                ans = Math.max(ans, (long) sum * num2);
            }
        }
        return ans;
    }
}