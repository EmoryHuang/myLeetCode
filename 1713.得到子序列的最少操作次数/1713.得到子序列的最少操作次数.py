'''
Descroption: LeetCode 1713. �õ������е����ٲ�������
Author: EmoryHuang
Date: 2021-07-26 13:40:16
Method:
Ϊ�˵õ������е����ٲ���������������Ҫ�ĵõ����������е������������
�õ��������������֮�����Ǳ����ȷ��������Ҫ��ӵ�Ԫ������
����target�л�����ͬ������֪��ÿ�����ֶ�Ӧ������Ψһ
��������������еȼ���arr��target������ת���󹹳��������������
'''


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        n = len(target)
        hash = defaultdict(int)
        # ��¼target��Ԫ�ص��±�λ��
        for i, num in enumerate(target):
            hash[num] = i
        com = []
        for num in arr:
            # ����ǹ���Ԫ��
            if num in hash:
                # �õ����Ԫ����target�е��±�
                ind = hash[num]
                pos = bisect.bisect_left(com, ind)
                if pos < len(com):
                    com[pos] = ind
                else:
                    com.append(ind)
        return n - len(com)
