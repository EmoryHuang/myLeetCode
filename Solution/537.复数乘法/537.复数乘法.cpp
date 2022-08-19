/*
 * @Descroption: LeetCode 537. �����˷�
 * @Author: EmoryHuang
 * @Date: 2021-08-20 16:11:37
 * @Method:
 * �������������ʽ����ȡ��ʵ�����鲿
 * Ȼ���ո����˷�������㼴��
 */

class Solution {
   public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        int r1, r2;
        char plus;
        stringstream ss1(num1);
        stringstream ss2(num2);
        ss1 >> a1 >> plus >> b1;
        ss2 >> a2 >> plus >> b2;

        r1 = a1 * a2 - b1 * b2;
        r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};