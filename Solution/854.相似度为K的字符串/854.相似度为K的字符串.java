/*
 * @Descroption: LeetCode 854. 相似度为 K 的字符串
 * @Author: EmoryHuang
 * @Date: 2022-09-21 09:43:20
 * @Method:
 * dfs + 剪枝
 * 若s1和s2如果当前字符相同则继续向下搜索
 * 否则遍历s2中后面的字符，直到找到相同的字符
 * 到达末尾时停止，更新最小交换次数
 */


class Solution {
    int ans = 10000000;

    public int kSimilarity(String s1, String s2) {
        dfs(s1, s2, 0, 0);
        return ans;
    }

    void dfs(String s1, String s2, int idx, int cnt) {
        // 停止更新最小交换次数
        if (idx == s1.length()) {
            ans = Math.min(ans, cnt);
            return;
        }
        // 提前停止
        if (cnt >= ans)
            return;
        if (s1.charAt(idx) == s2.charAt(idx)) {
            // 如果当前字符相同则继续向下搜索
            dfs(s1, s2, idx + 1, cnt);
        } else {
            // 否则遍历l2中后面的字符，直到找到相同的字符
            for (int i = idx + 1; i < s2.length(); i++) {
                if (s2.charAt(i) == s1.charAt(idx)) {
                    s2 = swap(s2, idx, i);
                    dfs(s1, s2, idx + 1, cnt + 1);
                    s2 = swap(s2, idx, i);
                }
            }
        }
    }

    String swap(String s, int i, int j) {
        char[] arr = s.toCharArray();
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        return new String(arr);
    }
}