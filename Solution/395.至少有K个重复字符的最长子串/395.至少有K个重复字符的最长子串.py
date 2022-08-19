'''
Descroption: LeetCode 395. ������ K ���ظ��ַ�����Ӵ�
Author: EmoryHuang
Date: 2021-10-13 19:03:28
Method:
˫ָ��
����ֻ�����Сд��ĸ�����Ա���������ĸ������
��¼�ж����ַ�����Ҫ�󣬵������������ַ�������ʱ���´�
'''

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        ans = 0
        # ����������ĸ������
        for p in range(1, 27):
            hash = defaultdict(int)
            l, r = 0, 0
            # cnt ��ʾ���ֵ���ĸ������total ��ʾ������������ĸ����
            cnt, total = 0, 0
            for r in range(len(s)):
                hash[s[r]] += 1
                if hash[s[r]] == 1:  # ����������ĸ
                    cnt += 1
                if hash[s[r]] == k:  # ������������������ĸ
                    total += 1
                # ������ĸ���������� p
                while cnt > p:
                    hash[s[l]] -= 1
                    if hash[s[l]] == 0:
                        cnt -= 1
                    if hash[s[l]] == k - 1:
                        total -= 1
                    l += 1  # ��ָ������
                if cnt == total:
                    ans = max(ans, r - l + 1)
        return ans