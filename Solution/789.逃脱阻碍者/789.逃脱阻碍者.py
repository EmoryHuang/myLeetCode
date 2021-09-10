'''
Descroption: LeetCode 789. �����谭��
Author: EmoryHuang
Date: 2021-08-22 19:43:50
Method:
����Ŀ����˵����Ҳ���ǱȽ��Ƿ����谭�߱������ȵ���Ŀ�ĵ�
'''


class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        d = abs(target[0]) + abs(target[1])
        for ghost in ghosts:
            if abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= d:
                return False
        return True
