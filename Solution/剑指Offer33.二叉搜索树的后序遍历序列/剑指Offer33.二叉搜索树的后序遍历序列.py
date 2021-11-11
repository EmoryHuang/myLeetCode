'''
Descroption: ��ָ Offer 33. �����������ĺ����������
Author: EmoryHuang
Date: 2021-11-11 19:54:07
Method:
����ջ
ά��һ������ѣ�ֻҪջ��Ԫ�ػ��ȵ�ǰ�ڵ�󣬾ͱ�ʾ������������Ҫ�Ƴ�
ֱ��ջ��Ԫ��С�ڽڵ㣬����ջΪ��
��������ÿ���ڵ㣬��Ҫ�������ĸ�ҪС
'''


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        pre = float('inf')
        heap = []
        # �������
        for i in range(len(postorder) - 1, -1, -1):
            # ������Ԫ�ؽ�С
            if postorder[i] > pre:
                return False
            # ά��һ�������
            # ֻҪջ��Ԫ�ػ��ȵ�ǰ�ڵ�󣬾ͱ�ʾ������������Ҫ�Ƴ�
            # ջ������һ��Ԫ�ؾ��������ڵ�ĸ�
            while heap and postorder[i] < -heap[0]:
                pre = -heapq.heappop(heap)
            heapq.heappush(heap, -postorder[i])
        return True
