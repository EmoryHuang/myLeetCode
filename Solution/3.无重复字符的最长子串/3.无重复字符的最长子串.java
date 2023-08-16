/*
 * @Description: LeetCode 3. 无重复字符的最长子串
 * @Author: EmoryHuang
 * @Date: 2023-08-04 10:45:12
 * @Method:
 * 滑动窗口，如出现重复字符，则左端点右移
 */

import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);
            if (map.containsKey(ch)) {
                l = Math.max(l, map.get(ch) + 1);
            }
            map.put(ch, r);
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}