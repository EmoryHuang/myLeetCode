'''
Descroption: LeetCode 717. 1������2�����ַ�
Author: EmoryHuang
Date: 2022-02-20 10:32:07
Method:
���⣬��������ɨ�����һλ֮ǰ���ַ�������¼֮ǰ��ƥ��״̬
'''

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        idx, n = 0, len(bits)
        while idx < n - 1:
            if bits[idx] == 0:
                idx += 1
            else:
                idx += 2
        return idx == n - 1