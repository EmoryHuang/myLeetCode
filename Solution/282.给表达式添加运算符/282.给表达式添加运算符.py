'''
Descroption: LeetCode 282. �����ʽ��������
Author: EmoryHuang
Date: 2021-10-16 09:13:42
Method:
����
ʹ�û��ݿ������п��ܵĲ����������� '+', '-', '*'
����˷�ʱ���������ȼ������⣬��Ҫ��¼��һ���Ĳ�������ʹ�� pre ��¼
'''


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(path: str, idx: int, cur: int, pre: int) -> None:
            if idx == len(num):
                if cur == target:
                    ans.append(path)
                return
            for i in range(idx, len(num)):
                # ���ֲ����� 0 ��ͷ
                if num[idx] == '0' and i > idx:
                    break
                # �����õ����ܵ�����
                c = num[idx:i + 1]
                if idx == 0:
                    dfs(path + c, i + 1, int(c), int(c))
                else:
                    dfs(path + '+' + c, i + 1, cur + int(c), int(c))
                    dfs(path + '-' + c, i + 1, cur - int(c), -int(c))
                    # ����˷�ʱ���������ȼ������⣬��Ҫ��¼��һ���Ĳ�������ʹ�� pre ��¼
                    dfs(path + '*' + c, i + 1, cur - pre + pre * int(c), pre * int(c))

        ans = []
        dfs('', 0, 0, 0)
        return ans
