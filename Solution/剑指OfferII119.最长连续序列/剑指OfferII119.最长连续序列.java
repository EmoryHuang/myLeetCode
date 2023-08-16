/*
 * @Description: LeetCode 128. 最长连续序列
 * @Author: EmoryHuang
 * @Date: 2023-08-04 10:00:21
 * @Method:
 * set 保存出现过的元素
 */

import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int ans = 0;
        for (int num : set) {
            if (!set.contains(num - 1)) {
                int cur = num;
                int len = 1;
                while (set.contains(cur + 1)) {
                    len++;
                    cur++;
                }
                ans = Math.max(ans, len);
            }
        }
        return ans;
    }
}