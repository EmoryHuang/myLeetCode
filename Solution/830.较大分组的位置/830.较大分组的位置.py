'''
Descroption: LeetCode 830. �ϴ�����λ��
Author: EmoryHuang
Date: 2021-06-19 15:31:00
����˼·:
һ�α��������м���
�����ǰ�ַ����һ���ַ���ͬ���ҷ��鳤�ȴﵽ 3�������
'''


class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        cnt = 1
        ans = []
        for i in range(len(s)):
            if i == len(s) - 1 or s[i] != s[i + 1]:
                if cnt >= 3:
                    ans.append([i - cnt + 1, i])
                cnt = 1
            else:
                cnt += 1
        return ans
