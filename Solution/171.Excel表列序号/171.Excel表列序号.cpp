/*
 * @Descroption: LeetCode 171. Excel �������
 * @Author: EmoryHuang
 * @Date: 2021-04-20 16:25:36
 * @����˼·: ��[170. Excel ��������]�෴��26 ������ת 10 ����
 */

class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};