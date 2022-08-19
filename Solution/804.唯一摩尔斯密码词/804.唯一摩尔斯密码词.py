'''
Descroption: LeetCode 804. ΨһĦ��˹�����
Author: EmoryHuang
Date: 2021-07-26 14:42:30
Method:
ʹ��set��¼��ͬĦ��˹�����
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