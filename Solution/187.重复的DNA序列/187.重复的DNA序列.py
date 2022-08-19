'''
Descroption: LeetCode 187. �ظ���DNA����
Author: EmoryHuang
Date: 2021-10-08 16:36:30
Method:
�������� + ��ϣ��
�������ڴ�СΪ10��ʹ�ù�ϣ���¼�����г��ֵĴ���
'''


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        hash = defaultdict(int)
        ans = []
        for i in range(len(s) - 10 + 1):
            cur = s[i:i + 10]
            if hash[cur] == 1:
                ans.append(cur)
            hash[cur] += 1
        return ans
