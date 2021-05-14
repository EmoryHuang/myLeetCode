/*
 * @Descroption: LeetCode 9. ������
 * @Author: EmoryHuang
 * @Date: 2021-03-19 13:08:36
 * @����˼·: ��������תһ����ͨ�����෴ת���������ж��Ƿ�Ϊ������
 * ��һ�ַ����Ƿ�ת�������֣��ڶ��ַ����ο���ⷴתһ�����֣����������ַ�������
 */

class Solution {
   public:
    //����һ����ת��������
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long res = 0, temp = x;
        while (temp) {  //��ת��������
            res = res * 10 + temp % 10;
            temp /= 10;
        }
        return x == (int)res;
    }

    //����������תһ������
    // bool isPalindrome(int x) {
    //     if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    //     int res = 0;
    //     while (x > res) {  //��תһ������
    //         res = res * 10 + x % 10;
    //         x /= 10;
    //     }
    //     return x == res || x == res / 10;  //ż�����ַ���ֱ����ȣ�������ȥ����λ������
    // }

    //���������ַ���
    // bool isPalindrome(int x) {
    //     string s = to_string(x);
    //     int i = 0, j = s.length() - 1;  //��������ָ��
    //     while (i < j) {
    //         if (s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
};