'''
Descroption: LeetCode 30. �������е��ʵ��Ӵ�
Author: EmoryHuang
Date: 2022-06-23 09:04:10
Method:
ö����ʼλ�ã�������ͳ�Ƶ��ʸ����Ƿ�һ��
'''


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        cnts, step = Counter(words), len(words[0])
        # ö��������ʼλ��
        for i in range(len(s) - step * len(words) + 1):
            cnt = Counter()
            # ͳ�Ƶ��ʸ���
            for j in range(len(words)):
                word = s[i + j * step:i + (j + 1) * step]
                cnt[word] += 1
            if cnt == cnts:
                ans.append(i)
        return ans
