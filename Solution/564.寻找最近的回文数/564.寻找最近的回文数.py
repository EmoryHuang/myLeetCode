'''
Descroption: LeetCode 564. Ѱ������Ļ�����
Author: EmoryHuang
Date: 2022-03-02 09:06:01
Method:
���������������ԭ���Ľϸ�λ�������滻���Ӧ�Ľϵ�λ
������ͬ��Ҳ��һЩ������������磺
99 ������� 101 �����Ǹ���̰�����ɵ� 88 �� 1001

��������ÿһ�ֿ��ܣ��ҵ�����Ļ�����
1. ��ԭ����ǰ�벿���滻��벿��
2. ��ԭ����ǰ�벿�ּ�һ��Ľ���滻��벿��
3. ��ԭ����ǰ�벿�ּ�һ��Ľ���滻��벿��
4. ֱ�ӹ��� 999...999 �� 100...001 �Ļ�����
'''


class Solution:
    def nearestPalindromic(self, n: str) -> str:
        m = len(n)
        near = [10**(m - 1) - 1, 10**m + 1]
        # ԭ����ǰ�벿��
        pre = int(n[:(m + 1) // 2])

        # 1. ��ԭ����ǰ�벿���滻��벿��
        # 2. ��ԭ����ǰ�벿�ּ�һ��Ľ���滻��벿��
        # 3. ��ԭ����ǰ�벿�ּ�һ��Ľ���滻��벿��
        for i in range(pre - 1, pre + 2):
            # ��������ż������
            j = i if m % 2 == 0 else i // 10
            while j:
                i = i * 10 + j % 10
                j //= 10
            near.append(i)

        # Ѱ������Ļ�����
        ans, real = -1, int(n)
        for p in near:
            if p != real:  # ���ܵ�������
                if ans == -1 or abs(p - real) < abs(ans - real) or (
                        abs(p - real) == abs(ans - real) and p < ans):
                    ans = p
        return str(ans)