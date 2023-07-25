/*
 * @Descroption: LeetCode 2208. 将数组和减半的最少操作次数
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:19:10
 * @Method:
 * 贪心 + 大根堆
 * 每次选择数组中最大的数进行减半操作
 * 利用大根堆存储元素
 */

import java.util.*;

class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> queue = new PriorityQueue<>((a, b) -> b.compareTo(a));
        double sum = 0;
        for (int num : nums) {
            queue.offer((double) num);
            sum += num;
        }
        int cnt = 0;
        double cur = 0;
        while (cur * 2 < sum) {
            double num = queue.poll();
            cur += num / 2;
            queue.offer(num / 2);
            cnt++;
        }
        return cnt;
    }
}