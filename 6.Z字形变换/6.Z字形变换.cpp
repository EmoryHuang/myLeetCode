/*
 * @Descroption: LeetCode 6. Z ���α任
 * @Author: EmoryHuang
 * @Date: 2021-03-17 17:30:36
 * @����˼·: �����ҵ��� s����ÿ���ַ���ӵ����ʵ��С�֮����ϵ��±����м��ɡ�
 * ʹ��`cur`��¼��ǰ�У�ֻ�е����������ƶ�����������л������ƶ������������ʱ����ǰ����Żᷢ���ı䡣
 * PS��һ��ʼ�õĶ�ά���飬������⣬˲��о��Լ��ô�
 */

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.length();
        vector<string> row(min(numRows, len));
        int cur = 0;        //��ǰ��
        bool flag = false;  //��ʼʱ��������
        for (int i = 0; i < len; i++) {
            row[cur] += s[i];
            //��Ϊ��һ�л������һ�У���ת������
            if (cur == 0 || cur == numRows - 1) flag = !flag;
            cur += flag ? 1 : -1;  //���ϵ��»��ߴ��µ���
        }
        string ans;
        for (int i = 0; i < row.size(); i++) ans += row[i];
        return ans;
    }
};