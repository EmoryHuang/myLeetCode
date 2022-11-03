/*
 * @Descroption: LeetCode 1790. 仅执行一次字符串交换能否使两个字符串相等
 * @Author: EmoryHuang
 * @Date: 2022-10-11 09:12:30
 * @Method:
 * 计数
 * 遍历s1, s2, 不相等的字符只可能有0个或2个
 * 若不相等字符为2个，再判断字符是否相等
 */


class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int cnt = 0;
        char a = 0, b = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                cnt++;
                if (cnt > 2 || (cnt == 2 && (a != s2.charAt(i) || b != s1.charAt(i))))
                    return false;
                a = s1.charAt(i);
                b = s2.charAt(i);
            }
        }
        return cnt != 1;
    }
}