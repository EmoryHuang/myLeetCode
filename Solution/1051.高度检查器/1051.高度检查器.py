'''
Descroption: LeetCode 1051. �߶ȼ����
Author: EmoryHuang
Date: 2021-07-17 14:27:48
����˼·:
һ���ܼ򵥵�˼���ǽ�ԭ�����������Ȼ��������������ԭ������бȽ�
Ȼ������ж��ٸ�Ԫ��û��ָ����λ��

����Ͱ�����˼����Ա�������ʱ�临�Ӷ�ΪO(n)
'''


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        arr = [0] * 101
        # ʹ�� arr ��¼ÿ��Ԫ�ص�����
        for height in heights:
            arr[height] += 1
        ans = j = 0
        for i in range(1, len(arr)):
            # ÿ�δ�Ͱ���ó�һ����
            while arr[i] > 0:
                # ��ΪĬ�Ͼ��Ƿǵݼ���˳��ֱ���� heights �Ƚ�
                if heights[j] != i:
                    ans += 1
                j += 1
                arr[i] -= 1
        return ans
