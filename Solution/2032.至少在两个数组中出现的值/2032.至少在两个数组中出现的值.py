'''
Descroption: LeetCode 2032. ���������������г��ֵ�ֵ
Author: EmoryHuang
Date: 2021-10-16 19:19:08
Method:
��ϣ��
ʹ�ù�ϣ���¼3�����������ֳ��ֵ������������ִ������� 2 �ļ��� ans
'''


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int],
                      nums3: List[int]) -> List[int]:
        cnt = Counter(set(nums1)) + Counter(set(nums2)) + Counter(set(nums3))
        ans = []
        for key, val in cnt.items():
            if val >= 2:
                ans.append(key)
        return ans
