/*
 * @Descroption: LeetCode 1812. 判断国际象棋棋盘中一个格子的颜色
 * @Author: EmoryHuang
 * @Date: 2022-12-08 09:30:57
 * @Method:
 * 简单题，横竖序号相加若为奇数，则是白色，否则为黑
 */

import java.util.*;

class Solution {
    public boolean squareIsWhite(String coordinates) {
        return (coordinates.charAt(0) + coordinates.charAt(1)) % 2 == 1;
    }
}