'''
Descroption: LeetCode 826. ���Ź����Դﵽ�������
Author: EmoryHuang
Date: 2021-06-19 15:16:00
����˼·:
���չ���������С����
����ÿ�����ˣ��ҵ�������ɵĹ������������
'''


class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        # i ָ��� i ������
        # tmp Ϊ������ɵĹ������������
        i = ans = tmp = 0
        for cap in sorted(worker):  # ����ÿ������
            while i < len(jobs) and cap >= jobs[i][0]:
                tmp = max(tmp, jobs[i][1])  # �ҵ��������Ĺ���
                i += 1
            ans += tmp
        return ans
