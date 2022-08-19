'''
Descroption: LeetCode 1405. ������ַ���
Author: EmoryHuang
Date: 2022-02-07 10:20:58
Method:
����ʣ��������������
̰�Ĳ��ԣ�ÿ�ξ���������ʹ�õ�ǰ����������ĸ
ʹ������������ĸ: ����ַ�������С�� 2; ��������ַ����䲻��ͬ; ����������ĸ����
����ʹ�������ڶ������ĸ
'''


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ans = ''
        cnt = [[a, 'a'], [b, 'b'], [c, 'c']]
        while True:
            # ����ʣ��������������
            cnt.sort(reverse=True)
            if cnt[0][0] and (len(ans) < 2 or not ans[-2] == ans[-1] == cnt[0][1]):
                # ʹ������������ĸ
                #   ����������ĸ���� and (����ַ�������С�� 2 or ��������ַ����䲻��ͬ)
                ans += cnt[0][1]
                cnt[0][0] -= 1
            elif cnt[1][0]:
                # ʹ�������ڶ������ĸ
                ans += cnt[1][1]
                cnt[1][0] -= 1
            else:
                break
        return ans
