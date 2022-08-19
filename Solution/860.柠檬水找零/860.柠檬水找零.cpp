/*
 * @Descroption: LeetCode 860. 柠檬水找零
 * @Author: EmoryHuang
 * @Date: 2021-06-15 16:37:00
 * @解题思路:
 * 贪心思想，记录当前5美元和10美元的个数
 * 然后按顺序进行分类讨论
 */

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five == 0) return false;
                ten++;
                five--;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};