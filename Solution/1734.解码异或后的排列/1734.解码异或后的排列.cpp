/*
 * @Descroption: LeetCode 1734. �������������
 * @Author: EmoryHuang
 * @Date: 2021-05-11 15:21:36
 * @����˼·:
 * ����Ĺؼ������ `perm` ����Ԫ��
 * �������� `perm` ��ǰ `n` ��������������
 * `total = perm[0] ^ perm[1] ^ perm[2] ^ ... ^ perm[n]`
 * ����Ϊ `encoded[i] = perm[i] XOR perm[i + 1]`
 * ����� `total = perm[0] ^ encode[1] ^ ... ^ encode[n-1]`
 * Ȼ��Ϳ��Եõ���Ԫ�� `perm[0]`��
 * ֮���� [1720. �������������]���������ɡ�
 */

class Solution {
   public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int a = 0;  // a Ϊ perm ����Ԫ��
        for (int i = 1; i <= n + 1; i++) a ^= i;
        for (int i = n - 1; i >= 0; i -= 2) a ^= encoded[i];
        vector<int> ans(n + 1);
        ans[0] = a;
        for (int i = 0; i < n; i++) ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};