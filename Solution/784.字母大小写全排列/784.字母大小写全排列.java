/*
 * @Descroption: LeetCode 784. 字母大小写全排列
 * @Author: EmoryHuang
 * @Date: 2022-10-30 10:32:23
 * @Method:
 * dfs
 * 对于每个字符，若为数字则直接保留，若为字母则可以直接保留或是大小写转换
 * 大小写转换可以通过异或 32 进行
 */

class Solution {
    List<String> ans = new ArrayList<>();;

    void dfs(char[] cs, char[] cur, int idx) {
        if (idx == cs.length) {
            ans.add(new String(cur));
            return;
        }
        cur[idx] = cs[idx];
        dfs(cs, cur, idx + 1);
        if (Character.isLetter(cs[idx])) {
            cur[idx] = (char) (cs[idx] ^ 32);
            dfs(cs, cur, idx + 1);
        }
    }

    public List<String> letterCasePermutation(String s) {
        dfs(s.toCharArray(), new char[s.length()], 0);
        return ans;
    }
}