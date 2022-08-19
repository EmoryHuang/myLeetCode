'''
Descroption: 面试题 10.02. 变位词组
Author: EmoryHuang
Date: 2021-07-18 13:46:49
解题思路:
使用长度为 26 的数组记录每个字母出现的次数
然后以此作为键值，判断字符是否为同类
'''


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            hash[tuple(cnt)].append(s)
        return list(hash.values())