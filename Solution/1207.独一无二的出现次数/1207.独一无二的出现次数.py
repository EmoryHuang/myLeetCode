'''
Descroption: LeetCode 1207. ��һ�޶��ĳ��ִ���
Author: EmoryHuang
Date: 2021-06-21 21:08:00
����˼·:
���⣬ʹ��map��¼���ֳ��ֵĴ�����Ȼ����set�ų��ظ���
'''


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        c = Counter(arr).values()
        return len(c) == len(set(c))
