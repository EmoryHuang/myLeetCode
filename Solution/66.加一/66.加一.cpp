/*
 * @Descroption: LeetCode 66. ��һ
 * @Author: EmoryHuang
 * @Date: 2021-03-21 20:00:36
 * @����˼·: �������õ��Ǵ����Ӽ���˼·�������һλ��ʼ�ӣ�`carry`�洢��λ��`carry == 0`�˾��˳�
 */

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 0;
        digits[len - 1]++;
        for (int i = len - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            if (carry == 0) break;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};