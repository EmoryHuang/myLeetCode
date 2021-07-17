/*
 * @Descroption: LeetCode 1109. ����Ԥ��ͳ��
 * @Author: EmoryHuang
 * @Date: 2021-07-17 14:57:17
 * @����˼·:
 * ���˼�룬
 * ���԰���Ŀ���Ϊ�� l ���ϳ� num �ˣ��� r ���³� num ��
 * ÿ����λ������Ϊǰһ����λ���������ϵ�ǰ�����仯
 */

class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto booking : bookings) {
            int l = booking[0], r = booking[1], num = booking[2];
            ans[l - 1] += num;
            if (r < n) ans[r] -= num;
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
        return ans;
    }
};