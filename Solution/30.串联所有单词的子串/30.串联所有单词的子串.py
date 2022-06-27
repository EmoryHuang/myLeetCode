'''
Descroption: LeetCode 30. 串联所有单词的子串
Author: EmoryHuang
Date: 2022-06-23 09:04:10
Method:
枚举起始位置，按步长统计单词个数是否一致
'''


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        cnts, step = Counter(words), len(words[0])
        # 枚举所有起始位置
        for i in range(len(s) - step * len(words) + 1):
            cnt = Counter()
            # 统计单词个数
            for j in range(len(words)):
                word = s[i + j * step:i + (j + 1) * step]
                cnt[word] += 1
            if cnt == cnts:
                ans.append(i)
        return ans
