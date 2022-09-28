/*
 * @Descroption: LeetCode 850. 矩形面积 II
 * @Author: EmoryHuang
 * @Date: 2022-09-15 09:15:50
 * @Method:
 * 扫描线
 * 按x轴坐标对矩形进行排序，并进行x轴方向的扫描
 * 计算在每段区间的矩形高度，最后计算总和
 */


class Solution {
    int MOD = (int) 1e9 + 7;

    public int rectangleArea(int[][] rectangles) {
        // 将x轴坐标进行排序
        List<Integer> bound = new ArrayList<Integer>();
        for (int[] rect : rectangles) {
            bound.add(rect[0]);
            bound.add(rect[2]);
        }
        Collections.sort(bound);
        long ans = 0;
        // 按x轴进行扫描
        for (int i = 1; i < bound.size(); i++) {
            // 计算当前区间宽度
            int x1 = bound.get(i - 1), x2 = bound.get(i);
            int width = x2 - x1;
            if (width == 0)
                continue;
            // 获取在当前区间内的矩形在y轴的上下界
            List<int[]> lines = new ArrayList<>();
            for (int[] rect : rectangles) {
                if (rect[0] <= x1 && x2 <= rect[2])
                    lines.add(new int[] { rect[1], rect[3] });
            }
            Collections.sort(lines, (a, b) -> {
                return a[0] != b[0] ? a[0] - b[0] : a[1] - b[1];
            });
            // 计算当前区间在y轴的覆盖范围
            long height = 0, l = -1, r = -1;
            for (int[] cur : lines) {
                if (cur[0] > r) {
                    height += r - l;
                    l = cur[0];
                    r = cur[1];
                } else if (cur[1] > r) {
                    r = cur[1];
                }
            }
            height += r - l;
            ans += height * width;
            ans %= MOD;
        }
        return (int) ans;
    }
}