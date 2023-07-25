/*
 * @Descroption: LeetCode 136. 只出现一次的数字
 * @Author: EmoryHuang
 * @Date: 2023-07-21 11:11:55
 * @Method:
 * a ^ a = 0
 * a ^ 0 = a
 */

import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
}