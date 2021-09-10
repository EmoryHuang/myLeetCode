/*
 * @Descroption: LeetCode 1588. ������������������ĺ�
 * @Author: EmoryHuang
 * @Date: 2021-08-29 17:21:44
 * @Method:
 * ����һ��ǰ׺��
 * ǰ׺�Ͳ�ѯ����
 *
 * ����������ѧ
 * ͳ��ÿ���������������л���ֶ��ٴ�
 * λ��i������������ķ���Ϊ(i+1)/2, �ұ�Ϊ (n-i)/2
 * λ��i���ż���������ķ���Ϊi/2, �ұ�Ϊ (n-i-1)/2
 */

class Solution {
   public:
    // ����һ��ǰ׺��
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> nums(n + 1);
    //     for (int i = 0; i < n; i++) nums[i + 1] = nums[i] + arr[i];
    //     int ans = 0;
    //     for (int l = 0; l < n; l++)
    //         for (int len = 1; l + len <= n; len += 2) {
    //             int r = l + len - 1;
    //             ans += nums[r + 1] - nums[l];
    //         }
    //     return ans;
    // }

    // ����������ѧ
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l_odd = (i + 1) / 2, r_odd = (n - i) / 2;
            int l_even = i / 2, r_even = (n - i - 1) / 2;
            l_even++, r_even++;
            ans += (l_odd * r_odd + l_even * r_even) * arr[i];
        }
        return ans;
    }
};