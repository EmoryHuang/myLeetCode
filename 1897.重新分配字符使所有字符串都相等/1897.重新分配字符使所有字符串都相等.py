'''
Descroption: LeetCode 1897. ���·����ַ�ʹ�����ַ��������
Author: EmoryHuang
Date: 2021-07-20 19:58:39
����˼·:
ʹ�ù�ϣ���¼ÿ���ַ�������
���ַ��ĸ����������鳤�ȵ���������������
'''


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        mp = defaultdict(int)
        for word in words:
            for ch in word:
                mp[ch] += 1
        for ch in mp:
            if mp[ch] % len(words) != 0:
                return False
        return True
