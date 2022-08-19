/*
 * @Descroption: LeetCode 1734. 解码异或后的排列
 * @Author: EmoryHuang
 * @Date: 2021-05-11 15:21:36
 * @解题思路:
 * 问题的关键是求出 `perm` 的首元素
 * 由于数组 `perm` 是前 `n` 个正整数的排列
 * `total = perm[0] ^ perm[1] ^ perm[2] ^ ... ^ perm[n]`
 * 又因为 `encoded[i] = perm[i] XOR perm[i + 1]`
 * 因此有 `total = perm[0] ^ encode[1] ^ ... ^ encode[n-1]`
 * 然后就可以得到首元素 `perm[0]`，
 * 之后按照 [1720. 解码异或后的数组]的做法即可。
 */

class Solution {
   public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int a = 0;  // a 为 perm 的首元素
        for (int i = 1; i <= n + 1; i++) a ^= i;
        for (int i = n - 1; i >= 0; i -= 2) a ^= encoded[i];
        vector<int> ans(n + 1);
        ans[0] = a;
        for (int i = 0; i < n; i++) ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};