'''
Descroption: LeetCode 393. UTF-8 ������֤
Author: EmoryHuang
Date: 2022-03-13 13:14:34
Method:
λ���㣬���� utf-8 �Ĺ�����м��
ʹ�� count ��¼�ֽ�������� count == 0����˵���ǵ�һ���ֽ�
��� 0b110xxxxx, 0b1110xxxx, 0b11110xxx
��������һ�ֽ��Ƿ��� 0b10xxxxxx
'''


class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        count = 0
        for num in data:
            if count == 0:
                if num >> 5 == 0b110:
                    count = 1
                elif num >> 4 == 0b1110:
                    count = 2
                elif num >> 3 == 0b11110:
                    count = 3
                elif num >> 7:
                    return False
            else:
                if num >> 6 != 0b10:
                    return False
                count -= 1
        return count == 0