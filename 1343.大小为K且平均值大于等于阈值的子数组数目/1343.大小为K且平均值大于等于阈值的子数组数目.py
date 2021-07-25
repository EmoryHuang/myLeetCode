'''
Descroption: LeetCode 1343. ��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ
Author: EmoryHuang
Date: 2021-07-25 14:23:35
Method:
���⣬�̶����ȵĻ�������
'''


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        s = sum(arr[:k])
        ans = 0 if s / k < threshold else 1
        for i in range(k, len(arr)):
            s += arr[i]
            s -= arr[i - k]
            if s / k >= threshold:
                ans += 1
        return ans
