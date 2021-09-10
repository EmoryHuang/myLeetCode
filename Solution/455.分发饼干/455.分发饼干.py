'''
Descroption: LeetCode 455. �ַ�����
Author: EmoryHuang
Date: 2021-06-08 19:40:00
����˼·:
̰��˼�룬�� s �� g ��������Ȼ���жϵ�ǰ�����Ƿ�������㵱ǰ���ӵ�����
'''


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        ans, cookies = 0, 0
        g.sort()
        s.sort()
        while cookies < len(s) and ans < len(g):
            # ��ǰ���ɿ������㵱ǰ���ӵ�����
            if s[cookies] >= g[ans]:
                ans += 1
            cookies += 1
        return ans
