'''
Descroption: LeetCode 1904. ����ɵ������Ծ���
Author: EmoryHuang
Date: 2021-11-06 15:42:30
Method:
���⣬��ʱ��ת��Ϊ����
���ǽ���ʱ��ǰ���Խ��������һ���Ծֻ��ǿ�ʼʱ��ĵ�һ���Ծ�
Ȼ����������ɵ������Ծ���
'''


class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        sh, sm = startTime.split(':')
        fh, fm = finishTime.split(':')
        start = int(sh) * 60 + int(sm)
        end = int(fh) * 60 + int(fm)
        # �ڶ���
        if start > end:
            end += 24 * 60
        # ����ʱ��ǰ���Խ��������һ���Ծ�
        end = end // 15 * 15
        return max(0, (end - start)) // 15
