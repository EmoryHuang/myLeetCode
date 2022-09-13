/*
 * @Descroption: LeetCode 667. 优美的排列 II
 * @Author: EmoryHuang
 * @Date: 2022-09-08 09:37:03
 * @Method:
 * 找规律：1,k+1,2,k+1-1,3,k+1-2,...,n
 */

class Solution {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int idx = 0;
        for (int i = 1; i <= (k + 1) / 2; i++) {
            ans[idx++] = i;
            ans[idx++] = k + 2 - i;
        }
        if (k % 2 == 0)
            ans[idx++] = 1 + k / 2;
        for (int i = k + 2; i <= n; i++)
            ans[idx++] = i;
        return ans;
    }
}