'''
Descroption: LeetCode 1743. ������Ԫ�ضԻ�ԭ����
Author: EmoryHuang
Date: 2021-07-25 13:24:13
Method:
ʹ�ù�ϣ��洢����Ԫ��
���У���βԪ��ֻ�����һ�Σ���ˣ�ֻ��Ҫ���ҳ���βԪ��
Ȼ��������Ԫ��Ѱ�Ҽ���
'''


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        hash = defaultdict(list)
        for a, b in adjacentPairs:
            hash[a].append(b)
            hash[b].append(a)
        ans = []
        n = len(adjacentPairs) + 1
        for key, value in hash.items():
            # ��βԪ��ֻ����һ��
            if len(value) == 1:
                # ������Ԫ�غ����ڵ�Ԫ��
                ans.append(key)
                ans.append(value[0])
                break
        for i in range(2, n):
            next = hash[ans[i - 1]]  # ��һ��Ԫ�ص�����Ԫ��
            if next[0] == ans[i - 2]:
                ans.append(next[1])
            else:
                ans.append(next[0])
        return ans