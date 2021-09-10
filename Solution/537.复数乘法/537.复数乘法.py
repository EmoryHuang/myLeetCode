'''
Descroption: LeetCode 537. �����˷�
Author: EmoryHuang
Date: 2021-08-20 16:07:58
Method:
�������������ʽ����ȡ��ʵ�����鲿
Ȼ���ո����˷�������㼴��
'''


class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        real, imag = [0] * 2, [0] * 2
        for i, num in enumerate([num1, num2]):
            real[i], imag[i] = num.split('+')
            real[i], imag[i] = int(real[i]), int(imag[i][:-1])
        ans = [0] * 2  # ʵ��, �鲿
        ans[0] = real[0] * real[1] - imag[0] * imag[1]
        ans[1] = real[0] * imag[1] + real[1] * imag[0]
        return str(ans[0]) + '+' + str(ans[1]) + 'i'
