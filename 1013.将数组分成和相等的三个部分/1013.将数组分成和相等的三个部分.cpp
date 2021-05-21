/*
 * @Descroption: LeetCode 1013. ������ֳɺ���ȵ���������
 * @Author: EmoryHuang
 * @Date: 2021-05-21 13:38:59
 * @����˼·:
 * �����жϺ��Ƿ�Ϊ3�ı���
 * �������飬�ж��Ƿ��ܹ��ֳ�����
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