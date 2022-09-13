'''
Descroption: LeetCode 828. 统计子串中的唯一字符
Author: EmoryHuang
Date: 2022-09-06 09:34:30
Method:
使用哈希表记录每个字符出现的位置
对于每个字符，计算它从上一次出现到下一次出现的位置
共有(arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i])种可能
'''


class Solution:
    def uniqueLetterString(self, s: str) -> int:
        # 使用哈希表记录每个字符出现的位置
        hash = defaultdict(list)
        for i, c in enumerate(s):
            hash[c].append(i)
        ans = 0
        for arr in hash.values():
            arr = [-1] + arr + [len(s)]
            for i in range(1, len(arr) - 1):
                ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i])
        return ans