'''
Descroption: LeetCode 1304. ��Ϊ���N��Ψһ����
Author: EmoryHuang
Date: 2021-07-26 15:16:06
Method:
���⣬һ��һ��
'''


class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        if n % 2 == 1:
            ans.append(0)
        for i in range(1, n // 2 + 1):
            ans.append(i)
            ans.append(-i)
        return ans
