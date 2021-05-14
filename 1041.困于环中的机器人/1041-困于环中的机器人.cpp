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
                    x += X[flag];
                    y += Y[flag];
                } else if (instructions[i] == 'L')
                    flag = (flag + 1) % 4;
                else
                    flag = (flag + 3) % 4;
            }
        }
        return x == 0 && y == 0;
    }
};
