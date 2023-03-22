'''
Descroption: LeetCode 2469. 温度转换
Author: EmoryHuang
Date: 2023-03-21 09:21:20
Method:
简单题
'''


class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
