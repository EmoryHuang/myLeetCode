'''
Descroption: LeetCode 239. �����������ֵ
Author: EmoryHuang
Date: 2021-07-13 20:47:07
����˼·:
����һ�����ȶ���
ά��һ������ѣ�����������
�����ǰ���ֵ���ڻ��������ڣ��򵯳�
Ȼ�󽫶Ѷ�Ԫ�ؼ��� ans

����������������
ʹ��һ�����д洢���л�û�б��Ƴ����±�
���µ�Ԫ�����β��Ԫ����Ƚ�, ��֤����Ϊ�ݼ�����
�����ǰ���ֵ���ڻ��������ڣ��򵯳�
Ȼ�󽫶���Ԫ�ؼ��� ans
'''


class Solution:
    # ����һ�����ȶ���
    # def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    #     q = [(-nums[i], i) for i in range(k)]
    #     # Python Ĭ�ϵ����ȶ�����С����
    #     heapq.heapify(q)
    #     ans = [-q[0][0]]
    #     for i in range(k, len(nums)):
    #         heapq.heappush(q, (-nums[i], i))
    #         while q[0][1] <= i - k:
    #             heapq.heappop(q)
    #         ans.append(-q[0][0])
    #     return ans

    # ����������������
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        for i in range(k):
            # ��֤����Ϊ�ݼ�����
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
        ans = [nums[q[0]]]
        for i in range(k, len(nums)):
            # ��֤����Ϊ�ݼ�����
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            # �����ǰ���ֵ���ڻ��������ڣ��򵯳�
            while q[0] <= i - k:
                q.popleft()
            ans.append(nums[q[0]])
        return ans
