'''
Descroption: LeetCode 299. 猜数字游戏
Author: EmoryHuang
Date: 2021-07-30 13:36:23
Method:
使用一个哈希表存储数字是否出现
若guess中的数不是公牛，则 hash 减一
若secret中的数不是公牛，则 hash 加一

如果当前位置为正，则说明一定有来自secret中未匹配的字符
如果当前位置为负，则说明一定有来自guess中未匹配的字符
'''


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a, b = 0, 0
        hash = [0] * 10
        for i in range((len(secret))):
            if secret[i] == guess[i]:
                a += 1
            else:
                # 如果当前位置为正，则说明一定有来自secret中未匹配的字符
                if hash[int(guess[i])] > 0:
                    b += 1
                # 若guess中的数不是公牛，则 hash 减一
                hash[int(guess[i])] -= 1
                # 如果当前位置为负，则说明一定有来自guess中未匹配的字符
                if hash[int(secret[i])] < 0:
                    b += 1
                # 若secret中的数不是公牛，则 hash 加一
                hash[int(secret[i])] += 1
        return str(a) + 'A' + str(b) + 'B'
