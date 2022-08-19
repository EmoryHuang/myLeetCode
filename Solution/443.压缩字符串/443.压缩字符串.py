'''
Descroption: LeetCode 443. ѹ���ַ���
Author: EmoryHuang
Date: 2021-08-21 17:44:30
Method:
˫ָ��
Ѱ����ͬ���ַ����ƶ���ָ�룬��¼�ַ������������Դ˸����ַ���
ʹ�� tail ����ʶ�´�
'''


class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        l, r, tail = 0, 0, 0
        while r < n:
            # Ѱ����ͬ���ַ����ƶ���ָ��
            while r < n and chars[r] == chars[l]:
                r += 1
            cnt = r - l  # ��ͬ�ַ�����
            chars[tail] = chars[l]  # �����ַ�
            tail += 1
            if cnt > 1:
                # д������
                cnt_str = str(cnt)
                for c in cnt_str:
                    chars[tail] = c
                    tail += 1
            l = r
        return tail
