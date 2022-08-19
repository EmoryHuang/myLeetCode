'''
Descroption: LeetCode 1996. ��Ϸ������ɫ������
Author: EmoryHuang
Date: 2021-09-17 11:04:58
Method:
���� + ����ջ
���������ݼ�����������������
��ǰ�����������¼��ǰ��������
����ǰ������С��������������ôǰ��һ����һ������Ĺ��������ڵ�ǰ������
'''


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        n = len(properties)
        # ���������ݼ�����������������
        properties.sort(key=lambda x: (-x[0], x[1]))
        # ��¼��ǰ��������
        ans, maxdfs = 0, -1
        for i in range(n):
            # ���ڹ������ݼ�����
            # �������ǰ������С����������
            # ��ôǰ��һ����һ������Ĺ��������ڵ�ǰ������
            # ��������������ͬ����Ϊ��������������
            if maxdfs > properties[i][1]:
                ans += 1
            maxdfs = max(maxdfs, properties[i][1])
        return ans
