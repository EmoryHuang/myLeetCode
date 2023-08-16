/*
 * @Description: LeetCode 239. 滑动窗口最大值
 * @Author: EmoryHuang
 * @Date: 2023-08-04 13:02:23
 * @Method:
 * 使用一个队列存储所有还没有被移除的下标
 * 将新的元素与队尾的元素相比较, 保证队内为递减序列
 * 如果当前最大值不在滑动窗口内，则弹出
 * 然后将队首元素加入 ans
 */

import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<int[]> heap = new PriorityQueue<>((int[] a, int[] b) -> {
            return a[0] != b[0] ? b[0] - a[0] : b[1] - a[1];
        });
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        for (int i = 0; i < k; i++) {
            heap.offer(new int[]{nums[i], i});
        }
        ans[0] = heap.peek()[0];
        for (int i = k; i < n; i++) {
            heap.offer(new int[]{nums[i], i});
            while (heap.peek()[1] <= i - k) {
                heap.poll();
            }
            ans[i - k + 1] = heap.peek()[0];
        }
        return ans;
    }
}