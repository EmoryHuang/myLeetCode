'''
Descroption: LeetCode 1944. 队列中可以看到的人数
Author: EmoryHuang
Date: 2021-09-10 19:48:30
Method:
单调栈 + 逆序遍历
最开始尝试了正序遍历，啪一下就超时了
逆序遍历，维护一个递减栈，将第 i 个人与栈顶元素 j 比较，
若 heights[i] > heights[j]，说明 i 能够看到 j，i 左侧的人看不到 j，则出栈，比较下一个栈顶元素
否则 i 能够看到 j，i 看不到 j 右侧的人，退出比较
'''


class Solution:
    # 正序（超时）
    # def canSeePersonsCount(self, heights: List[int]) -> List[int]:
    #     n = len(heights)
    #     ans = [0] * n
    #     # 遍历所有元素
    #     # 最后一个元素右侧能看到的人数必定是 0
    #     for i in range(n - 1):
    #         # 若第 i 个人的身高 <= 第 i + 1 个人的身高，则结果必定为 1
    #         if heights[i] <= heights[i + 1]:
    #             ans[i] = 1
    #             continue
    #         # 维护一个大根堆
    #         heap = []
    #         # 在右侧寻找元素
    #         for j in range(i + 1, n):
    #             # 若第 i 个人和第 j 个人都比他们中间的人高
    #             # 即 min(heights[i], heights[j]) > 堆顶元素
    #             if not heap or min(heights[i], heights[j]) > -heap[0]:
    #                 heapq.heappush(heap, -heights[j])
    #         ans[i] = len(heap)
    #     return ans

    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        ans = [0] * n
        heap = []
        # 逆序遍历
        for i in range(n - 1, -1, -1):
            while heap:
                ans[i] += 1
                if heights[i] > heights[heap[-1]]:
                    # i 能够看到 j，i 左侧的人看不到 j，出栈，比较下一个栈顶元素
                    heap.pop()
                else:
                    # i 能够看到 j，i 看不到 j 右侧的人，退出比较
                    break
            heap.append(i)
        return ans
