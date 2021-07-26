'''
Descroption: LeetCode 1713. 得到子序列的最少操作次数
Author: EmoryHuang
Date: 2021-07-26 13:40:16
Method:
为了得到子序列的最少操作次数，我们想要的得到这两个序列的最长公共子序列
得到了最长公共子序列之后，我们便可以确定最少需要添加的元素数量
根据target中互不相同，我们知道每个数字对应的坐标唯一
于是最长公共子序列等价于arr用target的坐标转换后构成最长的上升子序列
'''


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        n = len(target)
        hash = defaultdict(int)
        # 记录target中元素的下标位置
        for i, num in enumerate(target):
            hash[num] = i
        com = []
        for num in arr:
            # 如果是公共元素
            if num in hash:
                # 得到这个元素在target中的下标
                ind = hash[num]
                pos = bisect.bisect_left(com, ind)
                if pos < len(com):
                    com[pos] = ind
                else:
                    com.append(ind)
        return n - len(com)
