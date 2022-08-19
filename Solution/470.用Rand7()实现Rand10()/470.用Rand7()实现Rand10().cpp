/*
 * @Descroption: LeetCode 470. �� Rand7() ʵ�� Rand10()
 * @Author: EmoryHuang
 * @Date: 2021-09-05 19:52:50
 * @Method:
 * �������� rand7()�����Եõ� [1, 49]
 * ��������ֻ��Ҫ [1, 10]����ô���Կ���ʹ�� [1, 40]
 * ÿ�������ɵĸ���Ϊ 4/49
 */

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        while (1) {
            int row = rand7();
            int col = rand7();
            int ind = (row - 1) * 7 + col;
            if (ind <= 40) {
                return 1 + (ind - 1) % 10;
            }
        }
        return 0;
    }
};