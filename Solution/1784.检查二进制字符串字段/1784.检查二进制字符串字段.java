/*
 * @Descroption: LeetCode 1784. 检查二进制字符串字段
 * @Author: EmoryHuang
 * @Date: 2022-10-03 10:00:02
 * @Method:
 * 简单题，记录数字变化的次数
 */

class Solution {
    public boolean checkOnesSegment(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(i + 1))
                cnt++;
        }
        return cnt < 2;
    }
}