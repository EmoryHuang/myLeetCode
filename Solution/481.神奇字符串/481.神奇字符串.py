'''
Descroption: LeetCode 481. 神奇字符串
Author: EmoryHuang
Date: 2022-10-31 09:27:55
Method:
双指针
指针 i 指向现在需要构造的对应的组的大小，指针 j 指向现在需要构造的对应组的位置
模拟神奇字符串并记录 1 的个数
'''


class Solution:

    def magicalString(self, n: int) -> int:
        if n < 4:
            return 1
        s = [''] * n
        s[:3] = '122'
        # 指针 i 指向现在需要构造的对应的组的大小
        # 指针 j 指向现在需要构造的对应组的位置
        ans, i, j = 1, 2, 3
        while j < n:
            # 当前需要构造的大小
            size = int(s[i])
            num = 3 - int(s[j - 1])
            while size and j < n:
                s[j] = str(num)
                ans += 1 if num == 1 else 0
                j += 1
                size -= 1
            i += 1
        return ans
