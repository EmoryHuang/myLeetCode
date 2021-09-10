'''
Descroption: LeetCode 1588. ������������������ĺ�
Author: EmoryHuang
Date: 2021-08-29 17:11:33
Method:
����һ��ǰ׺��
ǰ׺�Ͳ�ѯ����

����������ѧ
ͳ��ÿ���������������л���ֶ��ٴ�
λ��i������������ķ���Ϊ(i+1)/2, �ұ�Ϊ (n-i)/2
λ��i���ż���������ķ���Ϊi/2, �ұ�Ϊ (n-i-1)/2
'''


class Solution:
    # ����һ��ǰ׺��
    # def sumOddLengthSubarrays(self, arr: List[int]) -> int:
    #     n = len(arr)
    #     nums = [0] * (n + 1)
    #     for i in range(n):
    #         nums[i + 1] = nums[i] + arr[i]
    #     ans = 0
    #     for l in range(n):
    #         for length in range(1, n + 1 - l, 2):
    #             r = l + length - 1
    #             ans += nums[r + 1] - nums[l]
    #     return ans

    # ����������ѧ
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n, ans = len(arr), 0
        for i, num in enumerate(arr):
            l_odd, r_odd = (i + 1) // 2, (n - i) // 2
            l_even, r_even = i // 2, (n - i - 1) // 2
            l_even += 1
            r_even += 1
            ans += (l_odd * r_odd + l_even * r_even) * num
        return ans
