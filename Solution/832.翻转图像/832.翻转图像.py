'''
Descroption: LeetCode 832. ��תͼ��
Author: EmoryHuang
Date: 2021-06-23 19:57:00
����˼·:
һ�����ҷ�ת��һ���޸�����
ͬʱ�޸������ҶԳƵ�Ԫ��
'''


class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)
        for i in range(n):
            for j in range((n + 1) // 2):
                image[i][j], image[i][n - j - 1] = image[i][n - j - 1] ^ 1, image[i][j] ^ 1
        return image
