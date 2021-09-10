/*
 * @Descroption: LeetCode 65. ��Ч����
 * @Author: EmoryHuang
 * @Date: 2021-06-16 13:21:00
 * @����˼·:
 * ģ�⣬�������ۣ��ж��Ƿ��������
 */

class Solution {
   public:
    bool isNumber(string s) {
        bool hasNum = false, hasE = false, isFloat = false;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // ����λֻ������λ��E�ĺ�һλ
            if ((c == '+' || c == '-') && (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e'))
                ;
            // ֻ����һ��E, ǰ�����������, ����Ҳ����������
            else if ((c == 'E' || c == 'e') && !hasE && hasNum) {
                hasE = true;
                hasNum = false;
            } else if (c == '.' && !isFloat && !hasE)
                //ֻ����һ��С����, ������E�ĺ���
                isFloat = true;
            else if (isdigit(c))
                hasNum = true;
            else
                return false;
        }
        return hasNum;
    }
};