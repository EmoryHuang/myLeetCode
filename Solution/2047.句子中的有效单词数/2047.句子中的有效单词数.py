'''
Descroption: LeetCode 2047. 句子中的有效单词数
Author: EmoryHuang
Date: 2022-01-27 13:13:48
Method:
模拟
将句子按空格分隔成单词，然后判断单词是否有效
'''


class Solution:
    def countValidWords(self, sentence: str) -> int:
        ans = 0
        for s in sentence.split():
            flag = False
            for i, c in enumerate(s):
                # 不含数字，标点符号在结尾
                if c.isdigit() or c in '!.,' and i < len(s) - 1:
                    break
                if c == '-':
                    # 仅包含一个连字符，并且连字符两侧应当都存在小写字母
                    if flag or i == 0 or i == len(s) - 1 or not s[
                            i - 1].islower() or not s[i + 1].islower():
                        break
                    flag = True
                if i == len(s) - 1:
                    ans += 1
        return ans
