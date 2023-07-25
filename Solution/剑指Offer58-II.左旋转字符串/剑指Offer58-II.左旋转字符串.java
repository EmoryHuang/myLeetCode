/*
 * @Descroption: 剑指 Offer 58 - II. 左旋转字符串
 * @Author: EmoryHuang
 * @Date: 2023-07-24 09:34:45
 * @Method:
 * 通过从第n个字符开始，mod遍历字符串
 */

import java.util.*;

class Solution {
    public String reverseLeftWords(String s, int n) {
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = n; i < len + n; i++) {
            sb.append(s.charAt(i % len));
        }
        return sb.toString();
    }
}