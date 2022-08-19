'''
Descroption: LeetCode 470. �� Rand7() ʵ�� Rand10()
Author: EmoryHuang
Date: 2021-09-05 19:48:30
Method:
�������� rand7()�����Եõ� [1, 49]
��������ֻ��Ҫ [1, 10]����ô���Կ���ʹ�� [1, 40]
ÿ�������ɵĸ���Ϊ 4/49
'''

# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7


class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            row = rand7()
            col = rand7()
            ind = (row - 1) * 7 + col
            if ind <= 40:
                return 1 + (ind - 1) % 10
