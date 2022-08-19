'''
Descroption: ������ 10.02. ��λ����
Author: EmoryHuang
Date: 2021-07-18 13:46:49
����˼·:
ʹ�ó���Ϊ 26 �������¼ÿ����ĸ���ֵĴ���
Ȼ���Դ���Ϊ��ֵ���ж��ַ��Ƿ�Ϊͬ��
'''


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            hash[tuple(cnt)].append(s)
        return list(hash.values())