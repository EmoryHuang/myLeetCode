'''
Descroption: LeetCode 870. ����ϴ��
Author: EmoryHuang
Date: 2021-07-21 19:41:28
����˼·:
̰��˼�룬�������
���ַ�Ѱ����˵㣬�� nums1 ���ҵ����� nums2[i] ����Сֵ
�������ڣ��򷵻� nums1 �е���Сֵ
'''


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        nums1.sort()
        for i in range(len(nums2)):
            # ���ַ�Ѱ����˵�
            l, r = 0, len(nums1) - 1
            while l < r:
                mid = (l + r) >> 1
                if nums1[mid] > nums2[i]:
                    r = mid
                else:
                    l = mid + 1
            if nums1[l] > nums2[i]:
                # �ҵ����� nums2[i] ����Сֵ
                ans.append(nums1[l])
                del nums1[l]
            else:
                # ��û���ҵ����� nums2[i] ����Сֵ
                # �򷵻� nums1 �е���Сֵ
                ans.append(nums1[0])
                del nums1[0]
        return ans
