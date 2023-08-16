/*
 * @Description: LeetCode 56. 合并区间
 * @Author: EmoryHuang
 * @Date: 2023-08-04 14:17:20
 * @Method:
 * 按照左端点进行排序，合并右端点
 */

import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][2];
        }
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        for (int[] interval : intervals) {
            int l = interval[0], r = interval[1];
            if (ans.isEmpty() || ans.get(ans.size() - 1)[1] < l) {
                ans.add(new int[]{l, r});
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], r);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}