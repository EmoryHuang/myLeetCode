'''
Descroption: LeetCode 273. 整数转换英文表示
Author: EmoryHuang
Date: 2021-07-30 11:17:15
Method:
从低位到高位3位划分一个单位
也就是需要处理3位数字的英文表示，
将三位整数分解成一位整数和两位整数的英文表示
'''


class Solution:
    def numberToWords(self, num: int) -> str:
        num19 = [
            'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine',
            'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen',
            'Seventeen', 'Eighteen', 'Nineteen'
        ]
        high = [
            'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty',
            'Ninety'
        ]
        split = ['Thousand', 'Million', 'Billion']
        if num == 0:
            return 'Zero'

        def change_num(num: int) -> List[int]:
            if num < 20:
                return num19[num - 1:num]
            if num < 100:
                return [high[num // 10 - 2]] + change_num(num % 10)
            if num < 1000:
                return [num19[num // 100 - 1]] + ['Hundred'] + change_num(num % 100)
            for i, word in enumerate(split):
                if num < 1000**(i + 2):
                    return change_num(num // 1000**(i + 1)) + [word] + change_num(
                        num % 1000**(i + 1))

        return ' '.join(change_num(num))