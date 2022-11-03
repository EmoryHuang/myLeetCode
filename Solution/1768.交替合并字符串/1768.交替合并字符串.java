/*
 * @Descroption: LeetCode 1768. 交替合并字符串
 * @Author: EmoryHuang
 * @Date: 2022-10-23 10:45:10
 * @Method:
 * 双指针，分别记录两个字符串位置，交替遍历
 */


class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < m || j < n) {
            if (i < m)
                ans.append(word1.charAt(i++));
            if (j < n)
                ans.append(word2.charAt(j++));
        }
        return ans.toString();
    }
}