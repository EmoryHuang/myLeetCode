'''
Descroption: LeetCode 1818. ���Բ�ֵ��
Author: EmoryHuang
Date: 2021-07-14 20:11:40
����˼·:
���ַ�
����ÿ�����У��ҵ���ǰ��Ӧ��ֵ�ľ���ֵ diff
���ַ�Ѱ�� nums1 ����ӽ� nums2[i] �����֣��ҵ���õ��µĲ�ֵ
����Ϊ�Ǿ���ֵ�����Լ����ֵҪ�������ߣ�
��¼���Լ�С�����Ĳ�ֵ
'''


class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        sort = sorted(nums1)
        sum = max_diff = 0
        # ����ÿ������
        for i in range(n):
            a, b = nums1[i], nums2[i]
            if a == b:
                continue
            diff = abs(a - b)  # ��ǰ��Ӧ��ֵ�ľ���ֵ
            sum += diff  # ���Բ�ֵ��
            # ���ַ�Ѱ�� nums1 ����ӽ� b ������
            l, r = 0, n - 1
            while l < r:
                mid = (l + r + 1) // 2
                if sort[mid] <= b:
                    l = mid
                else:
                    r = mid - 1
            # �õ��µĲ�ֵ
            new_diff = abs(sort[l] - b)
            if l + 1 < n:
                # ��Ϊ�Ǿ���ֵ������Ҫ��������
                new_diff = min(new_diff, abs(sort[l + 1] - b))
            if new_diff < diff:
                # ��¼���Լ�С�����Ĳ�ֵ
                max_diff = max(max_diff, diff - new_diff)
        return (sum - max_diff) % 1000000007
