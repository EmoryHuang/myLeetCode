'''
Descroption: ��ָ Offer 31. ջ��ѹ�롢��������
Author: EmoryHuang
Date: 2021-07-03 14:22:32
����˼·:
ģ�⣬ʹ��stackģ����ջ��
��ջ�ǿգ�����ջ��Ԫ�ص��ڳ�ջԪ�أ����ջ
'''


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        cnt = 0
        for num in pushed:
            stack.append(num)
            # ��ջ�ǿգ�����ջ��Ԫ�ص��ڳ�ջԪ��
            while stack and cnt < len(popped) and stack[-1] == popped[cnt]:
                cnt += 1
                stack.pop()
        return cnt == len(popped)
