'''
Descroption: LeetCode 752. 打开转盘锁
Author: EmoryHuang
Date: 2021-06-25 16:36:00
解题思路:
创建「两个队列」分别用于两个方向的搜索
创建「两个哈希表」用于「解决相同节点重复搜索」和「记录转换次数」
每次从队列中取值进行扩展时，先判断哪个队列容量较少
如果在搜索过程中「搜索到对方搜索过的节点」，说明找到了最短路径
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
