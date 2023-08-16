/*
 * @Description: LeetCode 560. 和为 K 的子数组
 * @Author: EmoryHuang
 * @Date: 2023-08-04 11:19:23
 * @Method:
 * 前缀和 + 哈希表
 * 使用哈希表记录前缀和出现的次数
 */

import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int ans = 0, pre = 0;
        for (int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if (map.containsKey(pre - k)) {
                ans += map.get(pre - k);
            }
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }
        return ans;
    }
}