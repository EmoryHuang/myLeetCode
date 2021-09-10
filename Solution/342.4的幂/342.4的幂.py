'''
Descroption: LeetCode 342. 4����
Author: EmoryHuang
Date: 2021-05-31 19:15:22
����˼·:  
����һ��ѭ��

��������ȡģ
ͨ�� n ���� 3 �������Ƿ�Ϊ 1 ���ж� n �Ƿ��� 4 ����
'''


# ����һ��ѭ��
# class Solution:
#     def isPowerOfFour(self, n: int) -> bool:
#         if n == 1:
#             return True
#         if n <= 0 or n % 2 == 1:
#             return False
#         while n % 4 == 0:
#             n /= 4
#         return n == 1


# ��������ȡģ
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n == 1:
            return True
        if n <= 0 or n % 2 == 1:
            return False
        return n > 0 and (n & (n-1)) == 0 and n % 3 == 1