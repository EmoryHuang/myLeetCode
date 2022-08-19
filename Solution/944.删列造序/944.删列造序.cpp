/*
 * @Descroption: LeetCode 944. 删列造序
 * @Author: EmoryHuang
 * @Date: 2022-05-12 08:55:57
 * @Method:
 * 简单题，遍历比较当前行和上一行元素即可
 */


class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};