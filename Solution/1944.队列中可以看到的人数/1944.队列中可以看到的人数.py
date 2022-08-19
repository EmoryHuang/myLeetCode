'''
Descroption: LeetCode 1944. �����п��Կ���������
Author: EmoryHuang
Date: 2021-09-10 19:48:30
Method:
����ջ + �������
�ʼ���������������žһ�¾ͳ�ʱ��
���������ά��һ���ݼ�ջ������ i ������ջ��Ԫ�� j �Ƚϣ�
�� heights[i] > heights[j]��˵�� i �ܹ����� j��i �����˿����� j�����ջ���Ƚ���һ��ջ��Ԫ��
���� i �ܹ����� j��i ������ j �Ҳ���ˣ��˳��Ƚ�
'''


class Solution:
    # ���򣨳�ʱ��
    # def canSeePersonsCount(self, heights: List[int]) -> List[int]:
    #     n = len(heights)
    #     ans = [0] * n
    #     # ��������Ԫ��
    #     # ���һ��Ԫ���Ҳ��ܿ����������ض��� 0
    #     for i in range(n - 1):
    #         # ���� i ���˵���� <= �� i + 1 ���˵���ߣ������ض�Ϊ 1
    #         if heights[i] <= heights[i + 1]:
    #             ans[i] = 1
    #             continue
    #         # ά��һ�������
    #         heap = []
    #         # ���Ҳ�Ѱ��Ԫ��
    #         for j in range(i + 1, n):
    #             # ���� i ���˺͵� j ���˶��������м���˸�
    #             # �� min(heights[i], heights[j]) > �Ѷ�Ԫ��
    #             if not heap or min(heights[i], heights[j]) > -heap[0]:
    #                 heapq.heappush(heap, -heights[j])
    #         ans[i] = len(heap)
    #     return ans

    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        ans = [0] * n
        heap = []
        # �������
        for i in range(n - 1, -1, -1):
            while heap:
                ans[i] += 1
                if heights[i] > heights[heap[-1]]:
                    # i �ܹ����� j��i �����˿����� j����ջ���Ƚ���һ��ջ��Ԫ��
                    heap.pop()
                else:
                    # i �ܹ����� j��i ������ j �Ҳ���ˣ��˳��Ƚ�
                    break
            heap.append(i)
        return ans
