/*
 * @Descroption: LeetCode 168. Excel ��������
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:02:36
 * @����˼·: ������ת��Ϊ�ַ�������ȡ�࣬ͨ�� string ƴ��
 */

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            columnNumber--;
            ans = (char)(columnNumber % 26 + 65) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};