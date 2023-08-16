/*
 * @Description: LeetCode 763. 划分字母区间
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:52:50
 * @解题思路:
 * 贪心
 * 遍历串获取每个字符出现的最后位置
 * 之后使用双指针进行查找
 */

import java.util.*;

class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character, Integer> hash = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            hash.put(s.charAt(i), i);
        }
        int start = 0, end = 0;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            end = Math.max(end, hash.get(ch));
            if (end == i) {
                ans.add(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
}