'''
Descroption: LeetCode 391. 完美矩形
Author: EmoryHuang
Date: 2021-11-16 13:27:11
Method:
方法一: 哈希表
使用哈希表记录每个位置的顶点出现的次数
其中四个端点只会出现一次，其余的点出现的次数为 2 或 4
并且若小矩形面积之和等于大矩形面积

方法二：扫描线
使用四元组记录每条竖边, (x, y_min, y_max, flag)
按 x 位置将每条竖边排序 
使用 l1, l2 分别记录左右边缘
对于完美矩形的每一条非边缘的竖边，都「成对」出现（存在两条完全相同的左边和右边）
对于完美矩形的两条边缘竖边，最终必然相连成一条完整的（不重叠）的竖边。
'''


class Solution:
    # 方法一: 哈希表
    # def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
    #     cnt = defaultdict(int)
    #     # 左下，右下，左上，右上
    #     lb, rb, lt, rt = rectangles[0]
    #     # 大矩形面积
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
    #     # 若小矩形面积之和不等于大矩形面积，则不是完美矩形
    #     # 左下，左上，右下，右上只会出现一次
    #     if area != (rt - rb) * (lt - lb) or cnt[(lb, rb)] != 1 or cnt[
    #         (lb, rt)] != 1 or cnt[(lt, rb)] != 1 or cnt[(lt, rt)] != 1:
    #         return False
    #     del cnt[(lb, rb)], cnt[(lb, rt)], cnt[(lt, rb)], cnt[(lt, rt)]
    #     return all(c == 2 or c == 4 for c in cnt.values())

    # 方法二：扫描线
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        n = len(rectangles)
        # 使用四元组记录每条竖边
        # (x, y_min, y_max, flag)
        # flag 表示左右边缘
        rs = []
        for rect in rectangles:
            x, y, a, b = rect
            rs.append((x, y, b, 1))
            rs.append((a, y, b, -1))
        # 按 x 位置将每条竖边排序
        rs.sort()
        l, r = 0, 0
        while r < len(rs):
            # l1, l2 分别记录左右边缘
            l1, l2 = [], []
            while r < len(rs) and rs[r][0] == rs[l][0]:
                r += 1
            # 遍历横坐标相同的竖边
            for i in range(l, r):
                x, y1, y2, flag = rs[i]
                cur = l1 if flag == 1 else l2
                if not cur:
                    cur.append([y1, y2])
                else:
                    if cur[-1][1] > y1:  # 如果有重叠
                        return False
                    elif cur[-1][1] == y1:  # 如果能连接
                        cur[-1][1] = y2
                    else:  # 不能连接
                        cur.append([y1, y2])
            # 如果是最左或者最右的边
            if l == 0 or r == len(rs):
                if len(l1) + len(l2) != 1:
                    return False
            # 如果是中间的边
            else:
                if len(l1) != len(l2):
                    return False
                for i in range(len(l1)):
                    if l1[i] != l2[i]:
                        return False
            l = r
        return True
