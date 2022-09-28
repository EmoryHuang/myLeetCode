/*
 * @Descroption: LeetCode 面试题 01.02. 判定是否互为字符重排
 * @Author: EmoryHuang
 * @Date: 2022-09-27 09:12:25
 * @Method:
 * 简单题，判断字符是否相同
 */


class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int[] hash = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            hash[s1.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            hash[s2.charAt(i) - 'a']--;
            if (hash[s2.charAt(i) - 'a'] < 0)
                return false;
        }
        return true;
    }
}