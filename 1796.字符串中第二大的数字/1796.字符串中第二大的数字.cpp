/*
 * @Descroption: LeetCode 1796. �ַ����еڶ��������
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:00:36
 * @����˼·:
 * �����ַ���������ǰ���ִ������ֵ `max`������ `ans = max` ���Ҹ������ֵ��
 * ����ǰ���ִ��ڵڶ���ֵ��С�����ֵ������� `ans` Ϊ��ǰ����
 */

class Solution {
   public:
    int secondHighest(string s) {
        int len = s.size();
        int ans = -1, max = -1;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (num > max) {
                    ans = max;                       //�ڶ���ֵ
                    max = num;                       //�������ֵ
                } else if (num > ans && num != max)  //�����ڵڶ���ֵ��С�����ֵ
                    ans = num;
            }
        }
        return ans;
    }
};