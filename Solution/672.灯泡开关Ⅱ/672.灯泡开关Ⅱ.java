/*
 * @Descroption: LeetCode 672. 灯泡开关 Ⅱ
 * @Author: EmoryHuang
 * @Date: 2022-09-15 09:15:50
 * @Method:
 * 用基向量表示4个操作，操作1,2,4组成最大线性无关组
 * 按键控制基向量的系数，只能为0,1
 * 解空间元素个数最多为8
 */

class Solution {
    public int flipLights(int n, int presses) {
        if (presses == 0)
            return 1;
        if (n == 1)
            return 2;
        if (n == 2)
            return presses == 1 ? 3 : 4;
        if (n >= 3)
            return presses == 1 ? 4 : presses == 2 ? 7 : 8;
        return 8;
    }
}