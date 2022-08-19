/*
 * @Descroption: LeetCode 522. 最长特殊序列 II
 * @Author: EmoryHuang
 * @Date: 2022-06-27 09:04:57
 * @Method:
 * 枚举每个字符串，判断是否为独有子序列，维护独有子序列的最大长度
 */


class Solution {
   public:
    bool isSubsequence(string str1, string str2) {
        int p = 0, q = 0;
        while (p < str1.size() && q < str2.size()) {
            if (str1[p] == str2[q]) p++;
            q++;
        }
        return p == str1.size();
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1, n = strs.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
};