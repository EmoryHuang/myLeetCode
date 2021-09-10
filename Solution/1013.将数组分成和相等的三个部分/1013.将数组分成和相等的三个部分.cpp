/*
 * @Descroption: LeetCode 1013. 将数组分成和相等的三个部分
 * @Author: EmoryHuang
 * @Date: 2021-05-21 13:38:59
 * @解题思路:
 * 首先判断和是否为3的倍数
 * 遍历数组，判断是否能够分成三段
 */

class Solution {
   public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int num : arr) sum += num;
        if (sum % 3 != 0) return false;
        int tmp = 0, count = 0;
        for (int num : arr) {
            tmp += num;
            if (tmp == sum / 3) {
                count++;
                tmp = 0;
            }
        }
        return count >= 3;
    }
};