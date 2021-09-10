'''
Descroption: LeetCode 68. �ı����Ҷ���
Author: EmoryHuang
Date: 2021-09-09 19:16:33
Method:
ģ��
ά��ÿ�еĵ��ʣ�һֱ�� row ����ӵ��ʣ�ֱ���������Ϊֹ
�������һ�У�������룻����һ��ֻ��һ�����ʣ��������
������������������ ��ǰ�пո񳤶�spaceWidth����ǰ�е��ʸ���cnt
����ƽ����� avgSpace = spaceWidth // (cnt - 1)
���ⵥ�ʼ�� extraSpace = spaceWidth % (cnt - 1)
����ֻ��Ҫ��ǰ extraSpace ��������� avgSpace + 1 ���ո�
'''


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        n, i = len(words), 0
        ans = []
        while i < n:
            # �� row ����䵥��
            row = [words[i]]
            cur = len(words[i])
            i += 1
            # һֱ�� row ����ӵ��ʣ�ֱ���������Ϊֹ
            # ע�ⵥ��֮���пո���Ҫ�� 1
            while i < n and cur + 1 + len(words[i]) <= maxWidth:
                cur += 1 + len(words[i])
                row.append(words[i])
                i += 1

            # �������һ�У��������
            if i == n:
                s = ' '.join(row)
                ans.append(s + ' ' * (maxWidth - len(s)))
                break
            # ����һ��ֻ��һ�����ʣ��������
            cnt = len(row)
            if cnt == 1:
                ans.append(row[0] + ' ' * (maxWidth - len(row[0])))
                continue

            # �������
            wordWidth = cur - (cnt - 1)  # ��ǰ�е��ʳ���
            spaceWidth = maxWidth - wordWidth  # ��ǰ�пո񳤶�
            avgSpace = spaceWidth // (cnt - 1)  # ����ƽ�����
            extraSpace = spaceWidth % (cnt - 1)  # ���ⵥ�ʼ��
            s = ''
            for j, word in enumerate(row):
                s += word
                if j == cnt - 1: break
                # ����ƽ�����
                s += ' ' * avgSpace
                # ǰ extraSpace ��������� avgSpace + 1 ���ո�
                if extraSpace:
                    s += ' '
                    extraSpace -= 1
            ans.append(s)
        return ans