'''
Descroption: LeetCode 1967. ��Ϊ���ַ��������ڵ����е��ַ�����Ŀ
Author: EmoryHuang
Date: 2021-11-04 19:45:55
Method:
���⣬�����鿴�ַ��Ƿ����ַ����г���
'''


class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        for pattern in patterns:
            if pattern in word:
                ans += 1
        return ans