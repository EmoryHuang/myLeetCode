/*
 * @Descroption: LeetCode 1822. ����Ԫ�ػ��ķ���
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:41:00
 * @����˼·:
 * ���⣬������������������жϳ˻����
 */

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                neg++;
        }
        return neg % 2 == 0 ? 1 : -1;
    }
};