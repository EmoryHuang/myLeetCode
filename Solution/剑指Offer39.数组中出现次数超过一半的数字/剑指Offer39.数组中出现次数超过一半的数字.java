/*
 * @Description: 剑指 Offer 56 - I. 数组中数字出现的次数
 * @Author: EmoryHuang
 * @Date: 2023-08-02 10:44:20
 * @Method:
 * 哈希表
 */

import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<>();
        int n = nums.length;
        for (int num : nums) {
            hash.put(num, hash.getOrDefault(num, 0) + 1);
            if (hash.get(num) * 2 > n) {
                return num;
            }
        }
        return -1;
    }
}
