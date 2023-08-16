/*
 * @Description: LeetCode 833. 字符串中的查找与替换
 * @Author: EmoryHuang
 * @Date: 2023-08-15 09:24:45
 * @解题思路:
 * 模拟
 */

import java.util.*;

class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        int m = indices.length, n = s.length();
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            idx.add(i);
        }
        idx.sort((i, j) -> indices[i] - indices[j]);
        StringBuilder ans = new StringBuilder();
        int pt = 0;
        for (int i = 0; i < n;) {
            while (pt < m && indices[idx.get(pt)] < i) {
                pt++;
            }
            boolean success = false;
            while (pt < m && indices[idx.get(pt)] == i) {
                if (s.substring(i, Math.min(i + sources[idx.get(pt)].length(), n)).equals(sources[idx.get(pt)])) {
                    success = true;
                    break;
                }
                pt++;
            }
            if (success) {
                ans.append(targets[idx.get(pt)]);
                i += sources[idx.get(pt)].length();
            } else {
                ans.append(s.charAt(i));
                i++;
            }
        }
        return ans.toString();
    }
}