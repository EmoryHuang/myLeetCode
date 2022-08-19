'''
Descroption: LeetCode 443. 压缩字符串
Author: EmoryHuang
Date: 2021-08-21 17:44:30
Method:
双指针
寻找相同的字符，移动右指针，记录字符和数量，并以此覆盖字符串
使用 tail 来标识新串
'''


class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        l, r, tail = 0, 0, 0
        while r < n:
            # 寻找相同的字符，移动右指针
            while r < n and chars[r] == chars[l]:
                r += 1
            cnt = r - l  # 相同字符数量
            chars[tail] = chars[l]  # 更新字符
            tail += 1
            if cnt > 1:
                # 写入数字
                cnt_str = str(cnt)
                for c in cnt_str:
                    chars[tail] = c
                    tail += 1
            l = r
        return tail
