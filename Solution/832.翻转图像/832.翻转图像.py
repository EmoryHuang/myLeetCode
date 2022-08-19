'''
Descroption: LeetCode 832. 翻转图像
Author: EmoryHuang
Date: 2021-06-23 19:57:00
解题思路:
一边左右翻转，一边修改数字
同时修改了左右对称的元素
'''


class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)
        for i in range(n):
            for j in range((n + 1) // 2):
                image[i][j], image[i][n - j - 1] = image[i][n - j - 1] ^ 1, image[i][j] ^ 1
        return image
