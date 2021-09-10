/*
 * @Descroption: LeetCode 1979. �ҳ���������Լ��
 * @Author: EmoryHuang
 * @Date: 2021-08-23 13:52:03
 * @Method:
 * ŷ������㷨�����Լ��
 */

class Solution {
   public:
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int findGCD(vector<int>& nums) {
        int a = INT_MAX, b = INT_MIN;
        for (int num : nums) {
            a = min(a, num);
            b = max(b, num);
        }
        return gcd(a, b);
    }
};