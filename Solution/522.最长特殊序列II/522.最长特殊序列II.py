'''
Descroption: LeetCode 522. 最长特殊序列 II
Author: EmoryHuang
Date: 2022-06-27 09:01:15
Method:
枚举每个字符串，判断是否为独有子序列，维护独有子序列的最大长度
'''


class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def isSubsequence(str1, str2):
            p, q = 0, 0
            while p < len(str1) and q < len(str2):
                if str1[p] == str2[q]:
                    p += 1
                q += 1
            return p == len(str1)

        ans, n = -1, len(strs)
        for i in range(n):
            flag = True
            for j in range(n):
                if i != j and isSubsequence(strs[i], strs[j]):
                    flag = False
                    break
            if flag:
                ans = max(ans, len(strs[i]))
        return ans
