'''
Descroption: LeetCode 1239. �����ַ�������󳤶�
Author: EmoryHuang
Date: 2021-06-19 13:47:00
����˼·:
��collect�����ǰ�ҵ��Ŀ��н�
Ȼ�󿴵�ǰ�ַ����Ƿ���Ժ�collect�е�ƴ���ַ�������ƴ��
'''


class Solution:
    def maxLength(self, arr: List[str]) -> int:
        collect = ['']
        ans = 0
        for s in arr:
            add = []
            for c in collect:
                t = c+s
                if len(t) == len(set(t)):
                    add.append(t)
                    ans = max(len(t), ans)
            collect.extend(add)
        return ans
