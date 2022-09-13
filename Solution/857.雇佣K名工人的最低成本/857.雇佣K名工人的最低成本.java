/*
 * @Descroption: LeetCode 857. 雇佣 K 名工人的最低成本
 * @Author: EmoryHuang
 * @Date: 2022-09-11 13:55:30
 * @Method:
 * 贪心 + 大根堆
 * 可以定义每个工人的性价比为 quality / wage
 * 那么按照题目描述，k名工人的性价比由其中性价比最高的人决定
 * 最终的价格为，总工作质量 × k名工人的最高性价比
 * 具体来说，可以按照工人的性价比进行排序，使用大根堆维护工人工作质量
 * 遍历每个工人，维护大根堆元素数量为k，并且工作质量最小
 */


class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        double ans = 1e10;
        int totalq = 0;
        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b - a);
        Integer[] idx = new Integer[quality.length];
        for (int i = 0; i < quality.length; i++)
            idx[i] = i;
        Arrays.sort(idx, (a, b) -> quality[b] * wage[a] - quality[a] * wage[b]);
        for (int i : idx) {
            totalq += quality[i];
            heap.add(quality[i]);
            if (heap.size() > k)
                totalq -= heap.poll();
            if (heap.size() == k)
                ans = Math.min(ans, (double) totalq * wage[i] / quality[i]);
        }
        return ans;
    }
}