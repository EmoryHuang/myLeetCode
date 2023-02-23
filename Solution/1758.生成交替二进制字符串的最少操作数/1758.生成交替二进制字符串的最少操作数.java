/*
 * @Descroption: LeetCode 1758. 生成交替二进制字符串的最少操作数
 * @Author: EmoryHuang
 * @Date: 2022-11-29 09:18:12
 * @Method:
 * 将字符串与0101...和1010...比较
 */

class Solution {
    public int minOperations(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != (char) ('0' + i % 2))
                cnt++;
        }
        return Math.min(cnt, s.length() - cnt);
    }
}