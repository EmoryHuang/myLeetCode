'''
Descroption: LeetCode 1138. ��ĸ���ϵ�·��
Author: EmoryHuang
Date: 2021-08-23 15:53:56
Method:
������ĸ���ǱȽϹ���ģ���˿��Լ������ǰ��ĸ���ڵ�����
����ǰһ���ַ����ڵ�λ�ý��бȽϣ��������λ��ȷ��·��
ע�⣬���� z �ұ�û��λ�ã���������� z���ƶ�ʱ R �����ȼ����
'''


class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        row, col = 0, 0
        ans = ''
        for c in target:
            # ����ǰһ���ַ���λ��
            prow, pcol = row, col
            # ��ǰ�ַ����ڵ�λ��
            row, col = (ord(c) - ord('a')) // 5, (ord(c) - ord('a')) % 5
            ans += 'L' * (pcol - col) +'D' * (row - prow) + \
                    'U' * (prow - row) + 'R' * (col - pcol) + '!'
        return ans
