'''
Descroption: LeetCode 1894. �ҵ���Ҫ����۱ʵ�ѧ�����
Author: EmoryHuang
Date: 2021-09-10 14:51:36
Method:
��ѧ
��ͣ�ȡ�࣬�ҵ�n�ֺ�ʣ�µ�������Ȼ���ٱ���һ�Σ��ҵ���Ҫ�����λ��
'''


class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        cnt = k % sum(chalk)
        for i, num in enumerate(chalk):
            if cnt < num:
                return i
            cnt -= num
        return -1
