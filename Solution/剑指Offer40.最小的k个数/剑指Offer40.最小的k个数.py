'''
Descroption: ��ָ Offer 40. ��С��k����
Author: EmoryHuang
Date: 2021-07-12 20:59:44
����˼·:
����һ������
ֱ������ѡȡǰ k ��Ԫ��
����������
�����ѣ�ʹ����Ԫ��С�� k
������������˼��
С�ڵ��ڷֽ�ֵ pivot ��Ԫ�صĶ��ᱻ�ŵ��������ߣ����ڵĶ��ᱻ�ŵ�������ұ�
'''


class Solution:
    # ����һ������
    # def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
    #     return arr.sort()[:k]

    # ����������
    # def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
    #     heapq.heapify(arr)
    #     return nsmallest(k, arr)

    # ������������˼��
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:

        def partition(l: int, r: int) -> int:
            i = random.randint(l, r)
            arr[l], arr[i] = arr[i], arr[l]
            pivot = arr[l]
            left, right = l, r
            while left < right:
                while left < right and arr[right] >= pivot:
                    right -= 1
                while left < right and arr[left] <= pivot:
                    left += 1
                if left < right:
                    arr[left], arr[right] = arr[right], arr[left]
            arr[left], arr[l] = arr[l], arr[left]
            return left

        def selected(l: int, r: int) -> None:
            if l >= r:
                return
            pos = partition(l, r)
            if k == pos:
                return
            elif k > pos:
                selected(pos + 1, r)
            else:
                selected(l, pos - 1)

        selected(0, len(arr) - 1)
        return arr[:k]
