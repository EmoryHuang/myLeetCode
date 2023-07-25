/*
 * @Descroption: 剑指 Offer 05. 替换空格
 * @Author: EmoryHuang
 * @Date: 2023-07-24 09:30:55
 * @Method:
 * 遍历查找空格
 */

import java.util.*;

class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == ' ') {
                sb.append("%20");
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}