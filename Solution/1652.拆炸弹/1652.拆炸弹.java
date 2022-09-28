/*
 * @Descroption: LeetCode 1652. 拆炸弹
 * @Author: EmoryHuang
 * @Date: 2022-09-24 09:26:40
 * @Method:
 * 暴力遍历
 */

class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0)
            return ans;
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= k; j++) {
                    ans[i] += code[(i + j) % n];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = k; j < 0; j++) {
                    ans[i] += code[(i + j + n) % n];
                }
            }
        }
        return ans;
    }
}