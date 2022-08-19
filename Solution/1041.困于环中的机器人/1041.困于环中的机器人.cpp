/*
 * @Descroption: LeetCode 1041. 困于环中的机器人
 * @Author: EmoryHuang
 * @Date: 2021-03-24 20:03:36
 * @解题思路:
 * 建立四个方向的表示方法，遍历字符串进行运动
 * 只有 `LR`，重复四次之后回到 `[0,0]`，因此需要遍历 4 次
 */

class Solution {
   public:
    bool isRobotBounded(string instructions) {
        int X[4] = {0, 1, 0, -1};
        int Y[4] = {1, 0, -1, 0};
        int flag = 0;
        int x = 0, y = 0;
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < instructions.size(); i++) {
                if (instructions[i] == 'G') {
                    x += X[flag];  // 按指定方向前进
                    y += Y[flag];
                } else if (instructions[i] == 'L')
                    flag = (flag + 1) % 4;  // 左转
                else
                    flag = (flag + 3) % 4;  // 右转
            }
        }
        return x == 0 && y == 0;
    }
};