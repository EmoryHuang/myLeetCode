'''
Descroption: LeetCode 1109. ����Ԥ��ͳ��
Author: EmoryHuang
Date: 2021-07-17 14:54:59
����˼·:
���˼�룬
���԰���Ŀ���Ϊ�� l ���ϳ� num �ˣ��� r ���³� num ��
ÿ����λ������Ϊǰһ����λ���������ϵ�ǰ�����仯
'''


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for booking in bookings:
            # ��Ŀ�������Ǵ� 1 ��ʼ��
            l, r, num = booking
            ans[l - 1] += num
            if r < n:
                ans[r] -= num
        for i in range(1, n):
            ans[i] += ans[i - 1]
        return ans
