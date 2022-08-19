'''
Descroption: LeetCode 1508. ������������������
Author: EmoryHuang
Date: 2021-08-11 14:53:24
Method:
��������
�õ����е�������ĺ�֮�󣬶���������Ȼ�����ָ�����±귶Χ�ڵ�Ԫ��֮��
'''


class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sums = []
        for i in range(n):
            add = 0
            for j in range(i, n):
                add += nums[j]
                sums.append(add)
        sums.sort()
        ans = sum(sums[left - 1:right]) % 1000000007
        return ans