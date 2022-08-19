'''
Descroption: LeetCode 2000. 反转单词前缀
Author: EmoryHuang
Date: 2022-02-02 20:14:25
Method:
简单题，找到指定字符后反转前面的字符串
'''


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        i = word.find(ch) + 1
        return word[:i][::-1] + word[i:]
