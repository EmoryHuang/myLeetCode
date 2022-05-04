'''
Descroption: LeetCode 1823. �ҳ���Ϸ�Ļ�ʤ��
Author: EmoryHuang
Date: 2022-05-04 11:13:17
Method:
����һ: ����ģ��
�ڶ����з��� 1 �� n �����
ÿһ����Ϸ�У�������Ԫ��ȡ��������Ԫ���ڶ�β�����¼�����У��ظ��ò��� k - 1 ��
�� k �μ�Ϊʧ���ߣ�ֱ�������ֻʣ��һ����ң�����ʤ��

������: ��ѧ + ģ��
ÿ����ͬһ�����Թ̶����� k ��������
������һ�β����ķ����Ϊ����λ�õ���һ����
ͬʱ�����ģ��� n ��Ϊ n - 1
����� f(n, k) = (f(n - 1, k) + k) % n
'''

from collections import defaultdict, deque, Counter
from typing import List
import re
import math
import heapq
import collections
import bisect
import random
import datetime


class Solution:
    # ����һ: ����ģ��
    # def findTheWinner(self, n: int, k: int) -> int:
    #     q = deque(range(1, n + 1))
    #     while len(q) > 1:
    #         for _ in range(k - 1):
    #             q.append(q.popleft())
    #         q.popleft()
    #     return q[0]

    # ������: ��ѧ + ģ��
    def findTheWinner(self, n: int, k: int) -> int:
        ans = 0
        for i in range(2, n + 1):
            ans = (ans + k) % i
        return ans + 1
