/*
 * @Descroption: 剑指 Offer 58 - I. 翻转单词顺序
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:40:58
 * @Method:
 * split分割并反转
 */

import java.util.*;

class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        List<String> l = Arrays.asList(s.split("\\s+"));
        Collections.reverse(l);
        return String.join(" ", l);
    }
}