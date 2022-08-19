'''
Descroption: LeetCode 524. 通过删除字母匹配到字典里最长单词
Author: EmoryHuang
Date: 2021-09-14 11:24:30
Method:
双指针 + 排序
p, q 分别为指向 s 和 word 的指针
若字符相等，则p，q向右移动；否则，p向右移动
如果找到了一个字符串，则加入 ans
按长度和字典序排序 ans
'''


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        ans = []
        for word in dictionary:
            # p, q 分别为指向 s 和 word 的指针
            p, q = 0, 0
            while p < len(s) and q < len(word):
                if s[p] == word[q]:
                    p, q = p + 1, q + 1
                else:
                    p += 1
                # 如果找到了一个字符串
                if q == len(word):
                    ans.append(word)
                    break
        if not ans:
            return ''
        # 按长度和字典序排序
        ans.sort(key=lambda x: [-len(x), x])
        return ans[0]
