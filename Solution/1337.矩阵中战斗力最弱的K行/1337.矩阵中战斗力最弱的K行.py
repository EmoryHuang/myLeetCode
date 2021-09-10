'''
Descroption: LeetCode 1337. ������ս���������� K ��
Author: EmoryHuang
Date: 2021-08-01 12:40:42
Method:
���� + ��С��
���� 1 ���ǳ����� 0 ֮ǰ����ôʹ�ö��ַ�Ѱ���Ҷ˵㣬�ҵ�ÿ��1�ĸ���
Ȼ������С�ѣ��ҵ�ǰk����Сֵ��Ӧ����
'''


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        power = []
        for i, row in enumerate(mat):
            l, r = 0, n - 1
            while l < r:
                mid = l + r + 1 >> 1
                if row[mid] == 1:
                    l = mid
                else:
                    r = mid - 1
            l = l + 1 if row[l] == 1 else l
            power.append([l, i])
        ans = []
        heapq.heapify(power)
        for i in range(k):
            ans.append(heapq.heappop(power)[1])
        return ans
