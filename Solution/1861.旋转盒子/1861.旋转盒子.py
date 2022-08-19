'''
Descroption: LeetCode 1861. ��ת����
Author: EmoryHuang
Date: 2021-10-22 15:15:43
Method:
ģ��
����ʯͷ��ˮƽλ�ò��ᷢ���ı䣬��˿��Ա���ÿ�е�������
����ÿ�У��Ӻ���ǰ���б��������Ҹ��µײ�λ�ã���ʯͷ���µ��ײ�
'''


class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        for i in range(m):
            # bottom ��¼�ײ�λ��
            bottom = n
            for j in range(n - 1, -1, -1):
                if box[i][j] == '*':
                    # ����ǹ̶��ϰ������µײ�λ��
                    bottom = j
                elif box[i][j] == '#':
                    # �����ʯͷ
                    bottom -= 1
                    box[i][j], box[i][bottom] = box[i][bottom], box[i][j]
        # ˳ʱ����ת 90 ��
        return list(map(list, zip(*box[::-1])))