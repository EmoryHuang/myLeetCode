/*
 * @Descroption: LeetCode 860. ����ˮ����
 * @Author: EmoryHuang
 * @Date: 2021-06-15 16:37:00
 * @����˼·:
 * ̰��˼�룬��¼��ǰ5��Ԫ��10��Ԫ�ĸ���
 * Ȼ��˳����з�������
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