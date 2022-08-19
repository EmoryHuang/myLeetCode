'''
Descroption: LeetCode 599. �����б����С�����ܺ�
Author: EmoryHuang
Date: 2022-03-14 08:50:20
Method:
���⣬ʹ�ù�ϣ���¼ list1 ÿ��Ԫ�ص�����
Ȼ���� list2 ��Ѱ�� list1 �е�Ԫ�أ���ά����С������
'''


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hash = defaultdict(list)
        for i, name in enumerate(list1):
            hash[name].append(i)
        ans = []
        min_idx = float('inf')
        for i, name in enumerate(list2):
            if name in hash:
                idx = hash[name][0] + i
                if idx < min_idx:
                    min_idx = idx
                    ans = [name]
                elif idx == min_idx:
                    ans.append(name)
        return ans