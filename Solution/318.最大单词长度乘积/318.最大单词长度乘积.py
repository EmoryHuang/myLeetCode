'''
Descroption: LeetCode 318. ��󵥴ʳ��ȳ˻�
Author: EmoryHuang
Date: 2021-11-17 09:12:58
Method:
λ����
ʹ�� bits ��¼ÿ����ĸ�Ƿ����
Ȼ����� mask ʹ�� & ���㣬��Ϊ 0 ��˵��û���ظ���ĸ
'''


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        mask = []
        for i, word in enumerate(words):
            # ʹ�� bits ��¼ÿ����ĸ�Ƿ����
            bits = 0
            for c in word:
                bits |= 1 << (ord(c) - ord('a'))
            mask.append(bits)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                # & ���㣬��Ϊ 0 ��˵��û���ظ���ĸ
                if not (mask[i] & mask[j]):
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans
