'''
Descroption: LeetCode 944. ɾ������
Author: EmoryHuang
Date: 2022-05-12 08:54:45
Method:
���⣬�����Ƚϵ�ǰ�к���һ��Ԫ�ؼ���
'''


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans = 0
        for i in zip(*strs):
            if list(i) != sorted(i):
                ans += 1
        return ans
