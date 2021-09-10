/*
 * @Descroption: LeetCode 1138. ��ĸ���ϵ�·��
 * @Author: EmoryHuang
 * @Date: 2021-08-23 16:07:58
 * @Method:
 * ������ĸ���ǱȽϹ���ģ���˿��Լ������ǰ��ĸ���ڵ�����
 * ����ǰһ���ַ����ڵ�λ�ý��бȽϣ��������λ��ȷ��·��
 * ע�⣬���� z �ұ�û��λ�ã���������� z���ƶ�ʱ R �����ȼ����
 */

class Solution {
   public:
    string alphabetBoardPath(string target) {
        int row = 0, col = 0;
        string ans;
        for (auto c : target) {
            // ����ǰһ���ַ���λ��
            int prow = row, pcol = col;
            // ��ǰ�ַ����ڵ�λ��
            row = (c - 'a') / 5;
            col = (c - 'a') % 5;
            while (pcol > col) ans += 'L', pcol--;
            while (prow < row) ans += 'D', prow++;
            while (prow > row) ans += 'U', prow--;
            while (pcol < col) ans += 'R', pcol++;
            ans += '!';
        }
        return ans;
    }
};