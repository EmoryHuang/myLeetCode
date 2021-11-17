'''
Descroption: LeetCode 391. ��������
Author: EmoryHuang
Date: 2021-11-16 13:27:11
Method:
����һ: ��ϣ��
ʹ�ù�ϣ���¼ÿ��λ�õĶ�����ֵĴ���
�����ĸ��˵�ֻ�����һ�Σ�����ĵ���ֵĴ���Ϊ 2 �� 4
������С�������֮�͵��ڴ�������

��������ɨ����
ʹ����Ԫ���¼ÿ������, (x, y_min, y_max, flag)
�� x λ�ý�ÿ���������� 
ʹ�� l1, l2 �ֱ��¼���ұ�Ե
�����������ε�ÿһ���Ǳ�Ե�����ߣ������ɶԡ����֣�����������ȫ��ͬ����ߺ��ұߣ�
�����������ε�������Ե���ߣ����ձ�Ȼ������һ�������ģ����ص��������ߡ�
'''


class Solution:
    # ����һ: ��ϣ��
    # def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
    #     cnt = defaultdict(int)
    #     # ���£����£����ϣ�����
    #     lb, rb, lt, rt = rectangles[0]
    #     # ��������
    #     area = 0
    #     for rect in rectangles:
    #         x, y, a, b = rect
    #         area += (a - x) * (b - y)
    #         lb, lt = min(lb, x), max(lt, a)
    #         rb, rt = min(rb, y), max(rt, b)
    #         cnt[(a, b)] += 1
    #         cnt[(a, y)] += 1
    #         cnt[(x, y)] += 1
    #         cnt[(x, b)] += 1
    #     # ��С�������֮�Ͳ����ڴ���������������������
    #     # ���£����ϣ����£�����ֻ�����һ��
    #     if area != (rt - rb) * (lt - lb) or cnt[(lb, rb)] != 1 or cnt[
    #         (lb, rt)] != 1 or cnt[(lt, rb)] != 1 or cnt[(lt, rt)] != 1:
    #         return False
    #     del cnt[(lb, rb)], cnt[(lb, rt)], cnt[(lt, rb)], cnt[(lt, rt)]
    #     return all(c == 2 or c == 4 for c in cnt.values())

    # ��������ɨ����
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        n = len(rectangles)
        # ʹ����Ԫ���¼ÿ������
        # (x, y_min, y_max, flag)
        # flag ��ʾ���ұ�Ե
        rs = []
        for rect in rectangles:
            x, y, a, b = rect
            rs.append((x, y, b, 1))
            rs.append((a, y, b, -1))
        # �� x λ�ý�ÿ����������
        rs.sort()
        l, r = 0, 0
        while r < len(rs):
            # l1, l2 �ֱ��¼���ұ�Ե
            l1, l2 = [], []
            while r < len(rs) and rs[r][0] == rs[l][0]:
                r += 1
            # ������������ͬ������
            for i in range(l, r):
                x, y1, y2, flag = rs[i]
                cur = l1 if flag == 1 else l2
                if not cur:
                    cur.append([y1, y2])
                else:
                    if cur[-1][1] > y1:  # ������ص�
                        return False
                    elif cur[-1][1] == y1:  # ���������
                        cur[-1][1] = y2
                    else:  # ��������
                        cur.append([y1, y2])
            # ���������������ҵı�
            if l == 0 or r == len(rs):
                if len(l1) + len(l2) != 1:
                    return False
            # ������м�ı�
            else:
                if len(l1) != len(l2):
                    return False
                for i in range(len(l1)):
                    if l1[i] != l2[i]:
                        return False
            l = r
        return True
