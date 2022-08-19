'''
Descroption: LeetCode 795. �������������
Author: EmoryHuang
Date: 2021-08-15 12:24:59
Method:
��̬�滮
ʹ��count����������С�ڵ���x�������������
���Ľ����Ϊcount(right) - count(left - 1)
'''


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        def count(x: int) -> int:
            # ����������С�ڵ���x�������������
            ans = cur = 0
            for num in nums:
                cur = cur + 1 if num <= x else 0
                ans += cur
            return ans

        return count(right) - count(left - 1)
