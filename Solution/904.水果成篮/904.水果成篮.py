'''
Descroption: LeetCode 904. ˮ������
Author: EmoryHuang
Date: 2021-11-04 20:26:40
Method:
��������
����Ŀ������ת��һ�£������������Ԫ�ص��������
ʹ�ù�ϣ���¼�����е�Ԫ��
'''


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans, l = 0, 0
        cnt = Counter()
        for r, x in enumerate(fruits):
            cnt[x] += 1
            if len(cnt) >= 3:
                # ������������
                cnt[fruits[l]] -= 1
                # �����˵��ֵ��Ϊ 0 ��ɾ��
                if cnt[fruits[l]] == 0:
                    del cnt[fruits[l]]
                l += 1
            # ������󳤶�
            ans = max(ans, r - l + 1)
        return ans
