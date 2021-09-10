'''
Descroption: LeetCode 739. ÿ���¶�
Author: EmoryHuang
Date: 2021-07-19 15:50:09
����˼·:
ά��һ���ݼ�ջ���洢Ԫ��λ��
����ǰԪ�ش���ջ��Ԫ�أ����ҵ��˸��ߵ��¶ȣ����³�ջԪ�ض�Ӧ�ĵȴ�����
'''


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        stack = []
        for i, num in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < num:
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return ans
