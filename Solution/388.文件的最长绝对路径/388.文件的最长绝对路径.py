'''
Descroption: LeetCode 388. 文件的最长绝对路径
Author: EmoryHuang
Date: 2022-04-20 08:55:24
Method:
前缀和
使用字典记录每层的路径长度，作为前缀和
通过统计 '\t' 的个数来确定当前层数
'.' 判断是否是文件, 并更新最长绝对路径
'''


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        ans = 0
        # 使用字典记录每层的路径长度
        depth = {-1: 0}
        for line in input.split('\n'):
            # 通过统计 '\t' 的个数来确定当前层数
            d = line.count('\t')
            # 前缀和计算
            depth[d] = depth[d - 1] + len(line) - d
            # 判断是否是文件
            if '.' in line:
                # 添加 d 个 '\'
                ans = max(ans, depth[d] + d)
        return ans
