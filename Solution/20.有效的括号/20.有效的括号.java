/*
 * @Description: LeetCode 20. 有效的括号
 * @Author: EmoryHuang
 * @Date: 2023-08-15 09:53:35
 * @解题思路:
 * 栈模拟
 */

import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new LinkedList<>();
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (!st.isEmpty()) {
                    if (ch == ')' && st.pop() != '(') {
                        return false;
                    } else if (ch == ']' && st.pop() != '[') {
                        return false;
                    } else if (ch == '}' && st.pop() != '{') {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
}