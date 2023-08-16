/*
 * @Description: LeetCode 76. 最小覆盖子串
 * @Author: EmoryHuang
 * @Date: 2023-08-04 14:00:30
 * @Method:
 * 滑动窗口
 * 哈希表记录窗口内字符的使用情况，
 * 如果满足目标字符条件，则窗口左端点右移
 */

import java.util.*;

class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) {
            return "";
        }
        int left = 0, right = 0;
        Map<Character, Integer> target = new HashMap<>();
        Map<Character, Integer> source = new HashMap<>();
        for (char ch : t.toCharArray()) {
            target.put(ch, target.getOrDefault(ch, 0) + 1);
        }
        int cnt = 0, len = Integer.MAX_VALUE;
        String ans = "";
        while (right < s.length()) {
            char ch = s.charAt(right);
            right++;
            if (target.containsKey(ch)) {
                source.put(ch, source.getOrDefault(ch, 0) + 1);
                if (source.get(ch).equals(target.get(ch))) {
                    cnt++;
                }
            }

            // move left
            while (cnt == target.size()) {
                if (len > right - left) {
                    ans = s.substring(left, right);
                    len = right - left;
                }
                char old = s.charAt(left);
                left++;
                if (target.containsKey(old)) {
                    if (target.get(old).equals(source.get(old))) {
                        cnt--;
                    }
                    source.put(old, source.get(old) - 1);
                }
            }
        }
        return len == Integer.MAX_VALUE ? "" : ans;
    }
}