'''
Descroption: LeetCode 2047. �����е���Ч������
Author: EmoryHuang
Date: 2022-01-27 13:13:48
Method:
ģ��
�����Ӱ��ո�ָ��ɵ��ʣ�Ȼ���жϵ����Ƿ���Ч
'''


class Solution:
    def countValidWords(self, sentence: str) -> int:
        ans = 0
        for s in sentence.split():
            flag = False
            for i, c in enumerate(s):
                # �������֣��������ڽ�β
                if c.isdigit() or c in '!.,' and i < len(s) - 1:
                    break
                if c == '-':
                    # ������һ�����ַ����������ַ�����Ӧ��������Сд��ĸ
                    if flag or i == 0 or i == len(s) - 1 or not s[
                            i - 1].islower() or not s[i + 1].islower():
                        break
                    flag = True
                if i == len(s) - 1:
                    ans += 1
        return ans
