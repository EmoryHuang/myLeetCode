'''
Descroption: LeetCode 68. 文本左右对齐
Author: EmoryHuang
Date: 2021-09-09 19:16:33
Method:
模拟
维护每行的单词，一直往 row 中添加单词，直到不能添加为止
若是最后一行，则左对齐；若这一行只有一个单词，则左对齐
若是其他情况，计算出 当前行空格长度spaceWidth，当前行单词个数cnt
单词平均间隔 avgSpace = spaceWidth // (cnt - 1)
额外单词间隔 extraSpace = spaceWidth % (cnt - 1)
我们只需要在前 extraSpace 个单词添加 avgSpace + 1 个空格
'''


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        n, i = len(words), 0
        ans = []
        while i < n:
            # 向 row 中填充单词
            row = [words[i]]
            cur = len(words[i])
            i += 1
            # 一直往 row 中添加单词，直到不能添加为止
            # 注意单词之间有空格，需要加 1
            while i < n and cur + 1 + len(words[i]) <= maxWidth:
                cur += 1 + len(words[i])
                row.append(words[i])
                i += 1

            # 若是最后一行，则左对齐
            if i == n:
                s = ' '.join(row)
                ans.append(s + ' ' * (maxWidth - len(s)))
                break
            # 若这一行只有一个单词，则左对齐
            cnt = len(row)
            if cnt == 1:
                ans.append(row[0] + ' ' * (maxWidth - len(row[0])))
                continue

            # 其余情况
            wordWidth = cur - (cnt - 1)  # 当前行单词长度
            spaceWidth = maxWidth - wordWidth  # 当前行空格长度
            avgSpace = spaceWidth // (cnt - 1)  # 单词平均间隔
            extraSpace = spaceWidth % (cnt - 1)  # 额外单词间隔
            s = ''
            for j, word in enumerate(row):
                s += word
                if j == cnt - 1: break
                # 单词平均间隔
                s += ' ' * avgSpace
                # 前 extraSpace 个单词添加 avgSpace + 1 个空格
                if extraSpace:
                    s += ' '
                    extraSpace -= 1
            ans.append(s)
        return ans