/*
 * @Descroption: LeetCode 17. 电话号码的字母组合
 * @Author: EmoryHuang
 * @Date: 2023-07-21 09:37:22
 * @Method:
 * 回溯法
 */

import java.util.*;

class Solution {
    List<String> ans;
    String[] maps = new String[] { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public List<String> letterCombinations(String digits) {
        ans = new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }
        dfs(digits, 0, new StringBuilder());
        return ans;
    }

    void dfs(String digits, int idx, StringBuilder cur) {
        if (idx == digits.length()) {
            ans.add(cur.toString());
        } else {
            char ch = digits.charAt(idx);
            String letters = maps[ch - '0'];
            for (int i = 0; i < letters.length(); i++) {
                cur.append(letters.charAt(i));
                dfs(digits, idx + 1, cur);
                cur.deleteCharAt(idx);
            }
        }
    }
}