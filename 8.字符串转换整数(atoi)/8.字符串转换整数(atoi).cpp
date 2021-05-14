/*
 * @Descroption: LeetCode 8. �ַ���ת������ (atoi)
 * @Author: EmoryHuang
 * @Date: 2021-03-18 14:30:36
 * @����˼·: ����ת���Ĺ�����������ȥ���ַ���ǰ������0��
 * ֮���ж����������Ŷ�ȡ���֣�ֱ����������Ϊֹ
 */

class Solution {
   public:
    int myAtoi(string s) {
        int len = s.size();
        int flag = 1, i = 0;
        long ans = 0;
        while (s[i] == ' ') i++;     //ȥ��ǰ�����Ŀո�
        if (s[i] == '-') flag = -1;  //�ж�����
        if (s[i] == '-' || s[i] == '+') i++;
        while (i < len && isdigit(s[i])) {
            int temp = s[i] - '0';
            ans = ans * 10 + temp;
            i++;
            if (ans > INT_MAX) {  //�ж��Ƿ�Խ��
                return flag == 1 ? INT_MAX : INT_MIN;
            }
        }
        return ans * flag;
    }
};