'''
Descroption: LeetCode 239. 滑动窗口最大值
Author: EmoryHuang
Date: 2021-07-13 20:47:07
解题思路:
方法一：优先队列
维护一个大根堆，遍历所有数
如果当前最大值不在滑动窗口内，则弹出
然后将堆顶元素加入 ans

方法二：单调队列
使用一个队列存储所有还没有被移除的下标
将新的元素与队尾的元素相比较, 保证队内为递减序列
如果当前最大值不在滑动窗口内，则弹出
然后将队首元素加入 ans
'''


class Solution:
    # 方法一：优先队列
    # def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    #     q = [(-nums[i], i) for i in range(k)]
    #     # Python 默认的优先队列是小根堆
    #     heapq.heapify(q)
    #     ans = [-q[0][0]]
    #     for i in range(k, len(nums)):
    #         heapq.heappush(q, (-nums[i], i))
    #         while q[0][1] <= i - k:
    #             heapq.heappop(q)
    #         ans.append(-q[0][0])
    #     return ans

    # 方法二：单调队列
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        for i in range(k):
            # 保证队内为递减序列
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
        ans = [nums[q[0]]]
        for i in range(k, len(nums)):
            # 保证队内为递减序列
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            # 如果当前最大值不在滑动窗口内，则弹出
            while q[0] <= i - k:
                q.popleft()
            ans.append(nums[q[0]])
        return ans
