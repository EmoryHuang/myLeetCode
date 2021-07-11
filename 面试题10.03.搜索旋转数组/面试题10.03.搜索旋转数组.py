'''
Descroption: ������ 10.03. ������ת����
Author: EmoryHuang
Date: 2021-07-11 15:17:04
����˼·:
������������������ת�����飬��˻���Ҫ�ж� mid ��λ��
'''


class Solution:
    def search(self, arr: List[int], target: int) -> int:
        if not arr:
            return -1
        l, r = 0, len(arr) - 1
        while l <= r:
            if arr[l] == target:
                return l
            mid = (l + r) // 2
            if arr[mid] == target:
                r = mid
            elif arr[l] < arr[mid]:  # target��������
                if arr[l] <= target < arr[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            elif arr[l] > arr[mid]:  # target�����Ұ��
                if arr[mid] < target <= arr[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                l += 1
        return -1
