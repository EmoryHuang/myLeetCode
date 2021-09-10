/*
 * @Descroption: LeetCode 1442. �γ������������������Ԫ����Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-05-18 11:32:12
 * @����˼·:
 * ����һ������ѭ��
 * �������ǰ׺�� s
 * ����i��k
 * ��s[i]==s[k+1]ʱ�������ڵ�����һ��j������i��k���������Ŀ��һ����Ԫ��
 *
 * ������
 * ���a==bҲ����a^b=0��
 * ��ôarr[i]^arr[i+1]^����^arr[j]^����arr[k]�Ľ������0
 * ֻ��Ҫ������arr���ҵ�һЩ������Ԫ�أ����ǵ����������0����
 * ��ʱ����Ϊ[i,k]����������Ԫ��ĸ���Ϊ k - i
 * ��Ϊ�����ڵ�����һ��j������i��k���������Ŀ��һ����Ԫ��
 */

class Solution {
   public:
    //����һ
    // int countTriplets(vector<int>& arr) {
    //     int n = arr.size();
    //     int ans = 0;
    //     vector<int> s(n + 1);
    //     // ���ǰ׺�� s
    //     for (int i = 0; i < n; i++) s[i + 1] = s[i] ^ arr[i];
    //     for (int i = 0; i < n; i++) {
    //         for (int k = i + 1; k < n; k++) {
    //             if (s[i] == s[k + 1]) ans += k - i;
    //         }
    //     }
    //     return ans;
    // }

    // ������
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int sum = 0;
            for (int k = i; k < n; k++) {
                sum ^= arr[k];
                // �����Ϊ0����������
                if (sum == 0 && k > i) ans += (k - i);
            }
        }
        return ans;
    }
};