'''
Descroption: LeetCode 804. 唯一摩尔斯密码词
Author: EmoryHuang
Date: 2021-07-26 14:42:30
Method:
使用set记录不同摩尔斯密码词
'''


class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        ls = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
            ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
            ".--", "-..-", "-.--", "--.."
        ]
        st = set()
        for word in words:
            morstr = ''
            for c in word:
                morstr += ls[ord(c) - ord('a')]
            st.add(morstr)
        return len(st)