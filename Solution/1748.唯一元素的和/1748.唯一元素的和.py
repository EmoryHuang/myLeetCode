'''
Descroption: LeetCode 1748. ΨһԪ�صĺ�
Author: EmoryHuang
Date: 2022-02-06 10:55:35
Method:
���⣬�������������٣�����ֱ����hash��¼Ԫ�س��ֵĴ���
'''


class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt = [0] * 101
        for num in nums:
            cnt[num] += 1
        ans = 0
        for i in range(101):
            if cnt[i] == 1:
                ans += i
        return ans
