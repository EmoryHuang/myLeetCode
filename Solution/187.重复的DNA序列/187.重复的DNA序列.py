'''
Descroption: LeetCode 187. 重复的DNA序列
Author: EmoryHuang
Date: 2021-10-08 16:36:30
Method:
滑动窗口 + 哈希表
滑动窗口大小为10，使用哈希表记录子序列出现的次数
'''


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        hash = defaultdict(int)
        ans = []
        for i in range(len(s) - 10 + 1):
            cur = s[i:i + 10]
            if hash[cur] == 1:
                ans.append(cur)
            hash[cur] += 1
        return ans
