'''
Descroption: LeetCode 1945. �ַ���ת����ĸ�λ����֮��
Author: EmoryHuang
Date: 2021-11-08 10:52:15
Method:
���⣬���ַ���ת��Ϊ���֣�Ȼ���ظ� k �β����õ���λ����֮��
'''


class Solution:
    def getLucky(self, s: str, k: int) -> int:
        ans = ''
        for c in s:
            ans += str(ord(c) - ord('a') + 1)
        while k:
            ans = str(sum([int(num) for num in ans]))
            k -= 1
        return int(ans)
