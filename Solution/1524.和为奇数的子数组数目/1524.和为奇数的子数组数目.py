'''
Descroption: LeetCode 1524. ��Ϊ��������������Ŀ
Author: EmoryHuang
Date: 2021-08-09 19:25:42
Method:
ǰ׺��
ͳ�Ƶ�ǰǰ׺�͵���ǰ׺������ż���ĸ���
���±� i ��λ�õ�ǰ׺����ż��ʱ����Ϊ�������������������Ϊ����ǰ׺�͵����� odd
���±� i ��λ�õ�ǰ׺��������ʱ����Ϊ�������������������Ϊż��ǰ׺�͵����� even
'''


class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        ans, sum = 0, 0
        odd, even = 0, 1
        for num in arr:
            sum += num
            ans += odd if sum % 2 == 0 else even
            if sum % 2 == 0:
                even += 1
            else:
                odd += 1
        return ans % 1000000007