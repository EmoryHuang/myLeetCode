/*
 * @Description: LeetCode 438. 找到字符串中所有字母异位词
 * @Author: EmoryHuang
 * @Date: 2023-08-04 11:05:23
 * @Method:
 * 滑动窗口
 */

import java.util.*;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = s.length(), m = p.length();
        List<Integer> ans = new ArrayList<>();
        if (n < m) {
            return ans;
        }
        int[] pcnt = new int[26];
        int[] scnt = new int[26];
        for (int i = 0; i < m; i++) {
            pcnt[p.charAt(i) - 'a']++;
            scnt[s.charAt(i) - 'a']++;
        }
        if (Arrays.equals(pcnt, scnt)) {
            ans.add(0);
        }
        for (int i = 0; i < n - m; i++) {
            scnt[s.charAt(i) - 'a']--;
            scnt[s.charAt(i + m) - 'a']++;
            if (Arrays.equals(pcnt, scnt)) {
                ans.add(i + 1);
            }
        }
        return ans;
    }
}