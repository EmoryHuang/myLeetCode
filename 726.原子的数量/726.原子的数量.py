'''
Descroption: LeetCode 726. ԭ�ӵ�����
Author: EmoryHuang
Date: 2021-07-05 21:58:48
����˼·:
��������ַ���
�������������¼����������ĸ���¼
������ ) ������ߵ�������Ϊ�������������ܱ���
������ ( �򽫶�Ӧ ) �ı�����ԭ
��������д��ĸ����ת�ַ��������� str �� num ���� map
'''


class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # s ��¼�ַ���num ��¼���֣�muls��¼�ܵı���
        s = num = ""
        mp, hash = defaultdict(int), []
        muls = 1
        # �Ӻ���ǰ�����ַ���
        for c in formula[::-1]:
            # ��������֣����¼
            if c.isdigit():
                num = c + num
            elif c == ')':
                # �� num Ϊ�գ���˵�������ұ�û�����֣�����Ϊ 1
                # ������Ϊ num
                mul = 1 if num == "" else int(num)
                num = ""  # ���¼�¼ num
                muls *= mul  # �����ܵı���
                hash.append(mul)
            elif c == '(':
                muls //= hash.pop()  # �����ܵı���
            else:
                s += c
                # ��������д��ĸ����ת�ַ����������� map
                if c.isupper():
                    if num == "":
                        mp[s[::-1]] += muls
                    else:
                        mp[s[::-1]] += int(num) * muls
                    s = num = ""
        return "".join(key if mp[key] == 1 else key + str(mp[key]) for key in sorted(mp.keys()))
