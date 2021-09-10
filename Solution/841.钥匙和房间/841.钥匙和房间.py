'''
Descroption: LeetCode 841. Կ�׺ͷ���
Author: EmoryHuang
Date: 2021-07-28 16:55:16
Method:
dfs��bfs
ʹ��һ���б��¼�Ѿ����ʵķ��䣬ʹ�ö��м�¼��ǰ���Դ򿪵ķ����
����ǰ����δ���ʣ�����Ϊ���ʣ��������е�Ҫ�Ǽ������
'''


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        q = deque()
        for key in rooms[0]:
            q.append(key)
        ans = [0]
        while q:
            num = q.popleft()
            if num not in ans:
                ans.append(num)
                for key in rooms[num]:
                    q.append(key)
        return len(ans) == n
