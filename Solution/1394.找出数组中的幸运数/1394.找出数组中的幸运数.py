'''
Descroption: LeetCode 1394. �ҳ������е�������
Author: EmoryHuang
Date: 2021-08-20 19:38:35
Method:
��ϣ���¼ÿ���ַ����ֵĴ���
������Ƶ�κ�������ֵ��С�����¼���ҵ����ֵ
'''


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        ans = -1
        for key, val in cnt.items():
            if key == val:
                ans = max(ans, key)
        return ans
