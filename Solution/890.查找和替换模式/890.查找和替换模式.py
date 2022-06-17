'''
Descroption: LeetCode 890. 查找和替换模式
Author: EmoryHuang
Date: 2022-06-12 09:49:40
Method:
使用哈希表记录字符之间的映射关系
遍历所有单词，依次检查模式是否匹配
'''


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(word, pattern):
            map = defaultdict(str)
            for ch, p in zip(word, pattern):
                if p in map:
                    if map[p] != ch:
                        return False
                else:
                    map[p] = ch
            return True

        return [w for w in words if match(w, pattern) and match(pattern, w)]