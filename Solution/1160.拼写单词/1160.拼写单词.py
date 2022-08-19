'''
Descroption: LeetCode 1160. 拼写单词
Author: EmoryHuang
Date: 2021-08-16 20:32:15
Method:
哈希表记录每个字符出现的次数
'''


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_cnt = Counter(chars)
        ans = 0
        for word in words:
            flag = True
            word_cnt = Counter(word)
            for c in word_cnt:
                if chars_cnt[c] < word_cnt[c]:
                    flag = False
                    break
            if flag:
                ans += len(word)
        return ans