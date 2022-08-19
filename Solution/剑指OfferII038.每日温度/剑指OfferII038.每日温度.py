'''
Descroption: ��ָ Offer II 038. ÿ���¶�
Author: EmoryHuang
Date: 2021-08-04 19:46:09
Method:
ά��һ������ջ
�������飬��������ջ��Ԫ�ظ����Ԫ�أ�����³�ջԪ�ض�Ӧ�ĵȴ�����
������������Ԫ����ջ
'''


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        ans = [0] * len(temperatures)
        for i, t in enumerate(temperatures):
            # ά���ݼ�ջ
            while stack and temperatures[stack[-1]] < t:
                # ���µȴ�����
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return ans