'''
Descroption: LeetCode 860. ����ˮ����
Author: EmoryHuang
Date: 2021-06-15 16:34:00
����˼·:
̰��˼�룬��¼��ǰ5��Ԫ��10��Ԫ�ĸ���
Ȼ��˳����з�������
'''


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if bills[0] != 5:
            return False
        five, ten = 0, 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                if five == 0:
                    return False
                ten += 1
                five -= 1
            else:
                if five > 0 and ten > 0:
                    five -= 1
                    ten -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True
