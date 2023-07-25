/*
 * @Descroption: LeetCode 215. 数组中的第K个最大元素
 * @Author: EmoryHuang
 * @Date: 2023-07-19 10:31:55
 * @Method:
 * 方法一：优先队列
 * 方法二：快排思想
 */

import java.util.*;

class Solution {
    // 方法一：优先队列
    // public int findKthLargest(int[] nums, int k) {
    //     PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> a - b);
    //     for (int x : nums) {
    //         if (q.size() < k || q.peek() < x)
    //             q.add(x);
    //         if (q.size() > k)
    //             q.poll();
    //     }
    //     return q.peek();
    // }

    // 方法二：快排思想

    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        return quickSelect(nums, 0, n - 1, n - k);
    }

    int quickSelect(int[] nums, int left, int right, int target) {
        int pos = partition(nums, left, right);
        if (pos == target) {
            return nums[pos];
        } else if (pos > target) {
            return quickSelect(nums, left, pos - 1, target);
        } else {
            return quickSelect(nums, pos + 1, right, target);
        }
    }

    int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int pos = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] <= pivot) {
                swap(nums, ++pos, i);
            }
        }
        swap(nums, left, pos);
        return pos;
    }

    int partition2(int[] nums, int left, int right) {
        int pivot = nums[left];
        int low = left, high = right;
        while (low < high) {
            while (low < high && nums[high] >= pivot) {
                high--;
            }
            while (low < high && nums[low] <= pivot) {
                low++;
            }
            if (low < high) {
                swap(nums, low, high);
            }
        }
        swap(nums, left, low);
        return low;
    }

    void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}