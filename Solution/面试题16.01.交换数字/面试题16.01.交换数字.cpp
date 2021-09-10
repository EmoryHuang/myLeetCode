/*
 * @Descroption: 面试题 16.01. 交换数字
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:29:38
 * @解题思路:
 * 因为只有两个数，所以其实可以直接交换返回
 * 异或：x ^ 0 = x, x ^ x = 0
 */

class Solution {
   public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};