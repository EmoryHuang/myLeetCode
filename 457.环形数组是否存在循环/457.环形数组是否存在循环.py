'''
Descroption: LeetCode 457. ���������Ƿ����ѭ��
Author: EmoryHuang
Date: 2021-08-07 14:17:33
Method:
ģ��
��ÿ���±� i ���г�����飬�����ĳ���±� i Ϊ�����㷢���ˡ�ѭ���������� True�����򷵻� False
'''


class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        def check(start: int) -> bool:
            cur = start
            cnt = 1  # ��¼������ɨ������±�����
            while True:
                if cnt > n: return False
                next = ((cur + nums[cur]) % n + n) % n
                # ��ȫ���������߸���
                if nums[start] > 0 and nums[next] < 0:
                    return False
                if nums[start] < 0 and nums[next] > 0:
                    return False
                if start == next:
                    # �ҵ����������ͬ���±�
                    return cnt > 1
                cur = next
                cnt += 1

        for i in range(n):
            if check(i):
                return True
        return False