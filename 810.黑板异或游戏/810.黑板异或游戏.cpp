/*
 * @Descroption: LeetCode 810. 黑板异或游戏
 * @Author: EmoryHuang
 * @Date: 2021-05-22 13:38:00
 * @解题思路:
 * 如果初始时黑板上所有数字异或结果等于 0，则 Alice 获胜。
 * 当数组的长度是偶数时，先手 Alice 总能找到一个数字，
 * 在擦掉这个数字之后剩余的所有数字异或结果不等于 0。
 * 在 Alice 擦掉这个数字后，黑板上剩下奇数个数字，无论 Bob 擦掉哪个数字，
 * 留给 Alice 的一定是黑板上剩下偶数个数字，
 * 此时 Alice 要么获胜，要么仍可以找到一个数字，在擦掉这个数字之后剩余的所有数字异或结果不等于 0，
 * 当数组的长度是奇数时同理，Bob 一定获胜
 */

class Solution {
   public:
    bool xorGame(vector<int>& nums) {
        int orx = 0;
        for (int num : nums) orx ^= num;
        if (orx == 0 || nums.size() % 2 == 0) return true;
        return false;
    }
};