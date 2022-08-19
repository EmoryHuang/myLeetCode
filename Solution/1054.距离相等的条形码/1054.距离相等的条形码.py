'''
Descroption: LeetCode 1054. ������ȵ�������
Author: EmoryHuang
Date: 2021-09-07 20:13:44
Method:
����һ��ֱ������
���ù�ϣ��ͳ��Ԫ�ص����������Ӵ�С��������
Ȼ���λ���룬��Ԫ�ص�Ƶ�δ�С˳�򣬽�Ԫ�ظ�λ����
����������
�뷽��һ���ƣ���ͬ�ľ��ǲ�ֱ�������ʹ�ô����
'''


class Solution:
    # ����һ��ֱ������
    # def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
    #     n = len(barcodes)
    #     order = sorted([(val, key) for key, val in Counter(barcodes).items()],
    #                    reverse=True)
    #     cur = []
    #     # Ƶ�δ�С��Ԫ��
    #     for val, key in order:
    #         cur += [key] * val
    #     j = 0
    #     ans = [0] * n
    #     # ��Ԫ�ص�Ƶ�δ�С˳�򣬽�Ԫ�ظ�λ����
    #     for i in range(0, n, 2):
    #         ans[i] = cur[j]
    #         j += 1
    #     for i in range(1, n, 2):
    #         ans[i] = cur[j]
    #         j += 1
    #     return ans

    # ����������
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n = len(barcodes)
        # python ��С����
        order = [(-val, key) for key, val in Counter(barcodes).items()]
        heapq.heapify(order)
        cur = []
        while order:
            val, key = heapq.heappop(order)
            # Ƶ�δ�С��Ԫ��
            cur += [key] * -val
        j = 0
        ans = [0] * n
        # ��Ԫ�ص�Ƶ�δ�С˳�򣬽�Ԫ�ظ�λ����
        for i in range(0, n, 2):
            ans[i] = cur[j]
            j += 1
        for i in range(1, n, 2):
            ans[i] = cur[j]
            j += 1
        return ans
