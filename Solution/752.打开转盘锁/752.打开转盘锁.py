'''
Descroption: LeetCode 752. ��ת����
Author: EmoryHuang
Date: 2021-06-25 16:36:00
����˼·:
�������������С��ֱ������������������
������������ϣ�����ڡ������ͬ�ڵ��ظ��������͡���¼ת��������
ÿ�δӶ�����ȡֵ������չʱ�����ж��ĸ�������������
��������������С��������Է��������Ľڵ㡹��˵���ҵ������·��
'''


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0
        dead = set(deadends)
        if "0000" in dead:
            return -1
        m1 = {"0000": 0}
        m2 = {target: 0}
        q1 = deque(["0000"])
        q2 = deque([target])

        def spin(s: str) -> List[str]:
            for i in range(4):
                num = int(s[i])
                for j in [1, -1]:
                    yield s[:i] + str((num + j) % 10) + s[i + 1:]

        def update(q: deque, same: dict, other: dict) -> int:
            cur = q.popleft()
            step = same[cur]
            for s in spin(cur):
                if s not in dead and s not in same:
                    if s in other:
                        return 1 + step + other[s]
                    else:
                        q.append(s)
                        same[s] = step + 1

        while q1 and q2:
            if len(q1) <= len(q2):
                ans = update(q1, m1, m2)
            else:
                ans = update(q2, m2, m1)
            if ans:
                return ans
        return -1
